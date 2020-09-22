//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

//pointer = holds mem address of the value, rather than the value itself

//let's start with strings:
char *name = "Ilja";
//what this really does:
//1) allocates a local stack variable called name
//2) causes the string "Ilja" to appear somewhere in the program (after compilation)
//3) initializes name to point to that string (dereferences it, as we will see below)

void learning_pointers() {
    // define a local variable
    int a = 123;

    //creating a pointer
    //* means we'd like to follow it or "dereference"'" it
    //& means we'd like to get the address of a
    //thus together pointer = follow + address
    int *pointer_to_a = &a;

    //without the star we're getting the ADDRESS of a
    printf("%x\n", pointer_to_a);

    //with the star we're getting the CONTENTS of a
    printf("%d\n", *pointer_to_a);

    //now let's change it. NOTE if we didn't put a star upfront, we'd be changing the mem address of a, not its contents
    *pointer_to_a = 666;
    printf("%d\n", *pointer_to_a);
}

void array_pointers() {
    int some_nums[5];
    int *ptr = some_nums; //in C array's name is a ptr to iself, so it's equivalent to doing &some_nums[0]
    int v = 2;

    //while the pointer has not reached the address of what would have been element 5
    //we can increment the pointer, and depending on the contents in the array (eg int, float, etc) it knows exactly by how many bytes to progress
    for ( ; ptr < &some_nums[5]; ptr++) {
        *ptr = v; //set contents to v
        v *= 2; //increment v
    }
    int i = 0;
    for (i=0; i < 5; i++) {
        printf("%d\n", some_nums[i]);
    }
}

void incr_ptr() {
    int a = 1;
    int *ptr = &a;
    *ptr += 1;
    printf("%d\n", *ptr);
}