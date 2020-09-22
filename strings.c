//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>
#include <memory.h>

void append() {
    // [] would not work here, need [number]
    char dest[20] = "hello";
    char src[20] = "world";
    strncat(dest,src,4); //concat 4 chars from src onto dest
    printf("%s\n", dest);
}

int strings_exc() {
    //define strings in 3 different ways
    char * first_name = "John";
    char last_name[] = "Doe";
    char name[100]; //empty

    //modify first letter
    last_name[0] = "B";

    //sprintf sends the output to "name"
    sprintf(name, "%s %s", first_name, last_name);
    if (strncmp(name, "John Boe", 100) == 0) {
        printf("Done!\n");
    }

    //modify first letter to the "null" character (ie shouldn't print anything)
    name[0]="\0";

    // concat 4 characters from first_name onto name (ie "John")
    strncat(name, first_name, 4);

    //concat 20 characters from last_name onto name (ie "Boe")
    strncat(name, last_name, 20);
    printf("%s\n", name);

    return 0;
}