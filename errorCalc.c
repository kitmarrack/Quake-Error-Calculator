#include <stdio.h>

int main (int argc, char *argv[]) {

    if (argc < 2) {
        printf("Please provide an input. \n");
        return 1;
    }

    float number = atof(argv[1]); //converting the string to a float
    printf("%f",number);

    float quakeOut = quakeFunc(number);
    float singleOut = singleFunc(number);
    double doubleOut = doubleFunc(number);

    print("%f", quakeOut);
    print("%f", singleOut);
    print("%f", doubleOut);
    
    return 0;
}


// Quake III function - 1/sqrt(x) for values of x

// Single Precision function - 1/sqrtf(x)

// Double Precision function - 1/sqrt(x)