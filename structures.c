//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

//create an ADT called point
typedef struct {
    int x;
    int y;
} ILJAS_POINT;


//create a filler function
ILJAS_POINT build_point(int x, int y) {
    ILJAS_POINT p;
    p.x = x;
    p.y = y;
    return p;
}


//create a printer function
void point_printer(ILJAS_POINT passed_point) {
    printf("The passed point is: %d, %d\n", passed_point.x, passed_point.y);
}


//create and print
void lets_do_it() {
    ILJAS_POINT p = build_point(1, 4);
    point_printer(p);
}


void structs_exc() {
    typedef struct {
        char *name;
        int age;
    } person;

    person john;
    john.name = "johnzio";
    john.age = 27;
    printf("%s is %d years old.", john.name, john.age);
}