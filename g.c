#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float getError(float f, double d) {
    return fabsf(f - (float)d) / fabsf((float)d);
}

float quakeFunc(float f) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = f * 0.5F;
    y = f;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));

    return y;
}

double estimate_d(double x) {
    return 1.0 / sqrt(x);
}

float c_output(float f) {
    return 1.0f / sqrtf(f);
}

int main() {
    const int N = 1000;

    float c_errs[N][2];  // [x, c_err]
    float q_errs[N][2];  // [x, q_err]

    float x_values[N];   // Array to store 1000 random numbers

    srand(time(NULL));  // Seed random generator

    // Fill the array with random floats between 0 and 1e6
    for (int i = 0; i < N; i++) {
        x_values[i] = ((float)rand() / RAND_MAX) * 1e6f;
        if (x_values[i] == 0) x_values[i] = 1e-6f; // avoid division by zero
    }

    // Iterate through the array
    for (int i = 0; i < N; i++) {
        float x = x_values[i];

        double d = estimate_d(x);
        float quake_val = quakeFunc(x);
        float c_val = c_output(x);

        float c_err = getError(c_val, d);
        float q_err = getError(quake_val, d);

        c_errs[i][0] = x;
        c_errs[i][1] = c_err;

        q_errs[i][0] = x;
        q_errs[i][1] = q_err;
    }

    // Print first 10 results
    printf(" x\t\tc_err\t\tq_err\n");
    for (int i = 0; i < 10; i++) {
        printf("%e\t%e\t%e\n", c_errs[i][0], c_errs[i][1], q_errs[i][1]);
    }

    // Optional: export data for plotting
    FILE *fp = fopen("errors.csv", "w");
    if (fp) {
        fprintf(fp, "x,c_err,q_err\n");
        for (int i = 0; i < N; i++) {
            fprintf(fp, "%e,%e,%e\n", c_errs[i][0], c_errs[i][1], q_errs[i][1]);
        }
        fclose(fp);
        printf("\nData written to errors.csv\n");
    }

    return 0;
}
