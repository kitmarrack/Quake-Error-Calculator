// Quake III function - 1/sqrt(x) for values of x

// Single Precision function - 1/sqrtf(x)

// Double Precision function - 1/sqrt(x)

#include <stdio.h>
#include <math.h>

int main(void) {
    const int n = 100;          // number of steps (0.01 to 1.00)
    const double start = 0.01;  // starting x value
    const double end = 1.0;     // ending x value
    const double step = (end - start) / (n - 1);

    for (int i = 0; i < n; i++) {
        double x = start + i * step;
        double d = 1.0 / sqrt(x);  // inverse square root (double precision)
        printf("%d\t%.6f\t%.12f\n", i + 1, x, d);
    }

    return 0;
}