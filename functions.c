//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

//what's different about functions in C:
//- can only return one value or no value
//- need to be declared before they can be called (either as headers or as actual funcs)

//this is a header
void print_big(int number);

int selective_printer() {
    int array[] = { 1, 11, 2, 22, 3, 33 };
    int i;
    for (i=0; i<6; i++) {
        print_big(array[i]);
    }
    return 0;
}

//this is the actual implementation
void print_big(int number) {
    if (number > 10) {
        printf("THE LINE IS %d\n", number);
    }
}