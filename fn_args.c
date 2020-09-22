//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

//diff between copying a variable and a pointer is that you either give the fn a fresh copy to play with, or you give it access to the original object

// -----------------------------------------------------------------------------
//case 1 - we pass the actual variable
void bad_addone(int n){
    n++;
}

void wont_work() {
    int n = 1;
    bad_addone(n);
    printf("%d\n", n);
}

// -----------------------------------------------------------------------------
//case 2 - we pass the pointer
void good_addone(int *n){
    (*n)++; //note how we're DEREFERENCING the variable over here
}

void will_work() {
    int n = 1;
    good_addone(&n); //note how we're passing a REFERENCE (the address) of the variable
    printf("%d\n", n);
}

// -----------------------------------------------------------------------------
//practice

typedef struct {
    char *name;
    int age;
} person;

void birthday(person *p) {
    (*p).age++;
}

int john_grows_old() {
    person john;
    john.name = 'john';
    john.age = 21;

    printf("today john is %d years old\n", john.age);
    birthday(&john);
    printf("yay, now john is %d years old\n", john.age);

    return 0;
}