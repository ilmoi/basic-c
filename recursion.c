//
// Created by Ilja Moisejevs on 8/16/20.
//

#include <stdio.h>

unsigned int factorial(unsigned int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

void call_fact() {
    unsigned int result = factorial(5);
    printf("%u\n", result);
}