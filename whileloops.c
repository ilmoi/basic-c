//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

int whileloops_exc() {
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    while (i<10) {
        i++;
        if (array[i] < 5) {
            continue;
        } else if (array[i] > 10) {
            break;
        }
        printf("%d\n", array[i]);
    }
}