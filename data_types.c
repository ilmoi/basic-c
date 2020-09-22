#include <stdio.h>

int dt_cls() {
    // not there is NO boolean type, instead we write
    #define BOOL char
    #define FALSE 0
    #define TRUE 1

    // int, of size word, typically is 4 bytes = from -2bn to +2bn
    int foo;
    int bar = 1;
    int a = 0, b = 1;

    return 0;
}

int dt_exc() {
    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum = a+b+c;
    printf("%f", sum);
    return 0;
}
