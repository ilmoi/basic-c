//
// Created by Ilja Moisejevs on 8/16/20.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void* left, const void* right) {
    return (*(int*)right - *(int*)left);
}

void fn_pointers() {
    //first we DEFINE a function pointer
    //1)return type from function // 2)pointer to function // 3)args to function
    int (*cmp) (const void*, const void*);
    //next we CREATE it
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8};

    //finally we use it. todo fucking unclear why you need to pass a pointer tho rather than actual function?
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);
    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray)) {
        printf("%d \t", iarray[c]);
        c++;
    }
}

// -----------------------------------------------------------------------------
// https://www.youtube.com/watch?v=p4sDgQ-jao4
// fn pointers = a way to assign a function to a variables and pass them in as parameters

int add(int x, int y, int z) {
    printf("adding %i, %i, %i\n", x, y, z);
    int total = x + y + z;
    return total;
}

int subtract(int x, int y, int z) {
    printf("subtracting %i, %i, %i\n", x, y, z);
    int total = x - y - z;
    return total;
}

//this time we define the function pointer right inside the function
//try removing it - it wont work
int do_operation(int (*fn) (int, int, int), int x, int y, int z) {
    return fn(x, y, z);
}

//another way to do it is through a typedef, to make it more readable
typedef int (*operation_pointer) (int, int, int);
int do_operation_readable(operation_pointer fn, int x, int y, int z) {
    return fn(x, y, z);
}

void practicing_fn_ptrs() {
    //read the below:
    //1)find the name of the function = that's our pointer
    //2)to the left its return type
    //3)to the right its arguments type
    //int (*add) (int, int, int);
    //int (*subtract) (int, int, int);
    int r = do_operation(add, 5, 4, 3);
    printf("%d\n", r);
    int r2 = do_operation_readable(subtract, 5, 4, 3);
    printf("%d\n", r2);

}


// -----------------------------------------------------------------------------
// fn pointers exercise

typedef void (*f_pointer) (int);

void f1(int var)
{
        printf("this is f1 and var is: %d\n", var);
}

void f2(int var)
{
        printf("this is f2 and var is: %d\n", var);
}

void f3(int var)
{
        printf("this is f3 and var is: %d\n", var);
}

int fn_ptrs_exc()
{
    /* define an array full of function pointers
    to the above functions, that take an `int` as
    their only argument */

    //I create an array and define each member's type as f_pointer above
    f_pointer fptrs[3];
    //fill in the array
    fptrs[0] = f1;
    fptrs[1] = f2;
    fptrs[2] = f3;

    //
    int c = 0;
    while(c < 3)
    {
        /* call the functions using the function pointers
        of the array at index `c` with `c` as an argument */
        fptrs[c](c);
        c++;
    }

  return 0;
}