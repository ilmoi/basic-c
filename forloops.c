//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

int forloops_exc() {
    int array[] = {1,2,3,4,5};
    int factorial = 1;

    //calc array length
    int length = sizeof(array) / sizeof(array[0]);

    int i;
    for (i=0; i<length; i++) {
        factorial *= array[i];
    }
    printf("%d", factorial);
    return 0;
}