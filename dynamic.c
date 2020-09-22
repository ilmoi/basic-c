//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>
#include <stdlib.h>

//allocating memory dynamically = allows us to store data without knowing upfront how much space we'll need
//must have a pointer ready, where we'll store the obj
//we'll use that pointer both to ACCESS and to FREE the mem given to us

void playing() {
    //create an ADT like before
    typedef struct {
        char *name;
        int age;
    } person;

    //this tells the compiler to dynamically find just enough space to fit in a person object and return a POINTER to that
    person *new_person = (person *) malloc(sizeof(person));

    //we use these bois when we're given a POINTER to a struct rather than a struct itself
    new_person->name = "ilja";
    new_person->age = 27;

    //we can now access that person like this
    //get the mem address (notice how it's CHANGING)
    printf("first lets print the address of the pointer: %x \n", new_person);
    printf("first lets print the address of the pointer: %d \n", new_person);

    //get the actual item
    printf("first lets print the address of the pointer: %d \n", *new_person);

    //get its attributes
    printf("now lets print the age: %d \n", new_person->age);

    //FUCK ME. YOU HAVE TO WRITE THE FUCKING NAME IN "" NOT ''.
    printf("now lets print the name: %s \n", new_person->name);

    free(new_person);
}

// -----------------------------------------------------------------------------
// gary explains tut

void simple_mem() {
    //we're gonna request some mem
    void *ptr = malloc(1024);

    //then free it
    free(ptr);

    printf("done!");
}

void string_mem() {
    //this time we're allocating memory to a string, so we're using char
    char *ptr = (char *) malloc(1024);

    ptr[0] = 'a';
    ptr[1] = 0; //marks the end of the string
    printf("buffer: %s\n", ptr);

    free(ptr);
}



// -----------------------------------------------------------------------------
//another tut - https://www.y outube.com/watch?v=xDVC3wKjS64

//malloc
//takes as argument the size
//returns a void pointer (pointer that can point to any kind of obj - doesn't care) - but also CANT BE DEREFERENCED
//instead a void pointer needs to be type-casted into a relevant data type pointer - which is the thing you do in brackets like this (int *)

void array_of_ints() {

    //allocate enough space for 10 ints
    //when you see a STAR in front of a name WITH A TYPE DECLARED - the pointer is being DECLARED
    int *pointer_to_arr = (int *) malloc(10*sizeof(int));

    //loop and fill the array with increasing numbers
    int i = 0;
    int j = 2;
    for (i=0; i < 10; i++) {
        pointer_to_arr[i] = j;
        j *= 2;
    }

    //when you see a STAR in front of a name WITH NO TYPE = the pointer is being DEREFERENCED to get the target
    //2 equivalent ways to do it (because in C array's name points to first element):
    printf("%d\n", *pointer_to_arr);
    printf("%d\n", *(pointer_to_arr+1));
    printf("%d\n", *(pointer_to_arr+2));
    //2nd way
    printf("%d\n", pointer_to_arr[0]);
    printf("%d\n", pointer_to_arr[1]);
    printf("%d\n", pointer_to_arr[2]);

    // thus all the interaction with a dynamically allocated chunk of memory happens through POINTERS. You start with pointer at place [0] and incremenet it to move along
}

//calloc
//also returns a void pointer
//but takes 2 arguments - # of elements of a particular datatype and then size of each element
//ALSO sets all byte positions with value 0. So initializes every value to 0.


void another_array_of_ints() {

    int *pointer_to_arr = (int *) calloc(10, sizeof(int));

    int i = 0;
    int j = 2;
    for (i=0; i < 10; i++) {
        pointer_to_arr[i] = j;
        j *= 2;
    }

    printf("%d\n", *pointer_to_arr);
    printf("%d\n", *(pointer_to_arr+1));
    printf("%d\n", *(pointer_to_arr+2));
}


//realloc
//if you have a dynamically allocated block of mem and want to change its size you use realloc
//if possible existing block will be extended, else a new block allocated


// -----------------------------------------------------------------------------

void pointer_exc() {
    typedef struct {
        int x;
        int y;
    } point;

    //create a null pointer to some point object
    point *mypoint = NULL;
    mypoint = (point*) malloc(sizeof(point));

    mypoint->x = 10;
    mypoint->y = 5;
    printf("mypoint coordinates are %d %d\n", mypoint->x, mypoint->y);

    free(mypoint);
}

void run_dem_dynamic_file() {
    //string_mem();
    //playing();
    //another_array_of_ints();
    pointer_exc();
}