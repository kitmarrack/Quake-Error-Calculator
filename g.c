// Online C compiler to run C program online
#include <stdio.h>

float getError(float f, float d) {
    float difference = f-d;
    float err = difference/f;
    
    return err;
}

float quake(float f) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    
    x2 = number * 0.5F;
    y = number;
    i = * ( long * ) &y;
    i = 0x5f3759df - ( i >> 1 );
    y = * ( float * ) &i;
    y = y * (threehalfs - ( x2 * y * y ))
    
    return y;
}

double estimate_d(double x) {
    return 1.0 / sqrt(x);
}

int main() {
    // Write C code here
    for (int i = 0; i < 1000; i++) {
        double x = 1e-6f + i * (1e6f - 1e-6f) / 999.0f;
        
        float d = estimate_d(x);
        
        float quake_val = quake(x)
        
        float err = getError(x, d);
        printf("%f\n", err);
    }
    
    return 0;
}