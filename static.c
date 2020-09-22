//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

int runner() {
    //because we added static here, the two calls below will build oin each other
    static int i = 0;
    i++;
    return i;
}

int printer() {
    printf("%d\n", runner());
    printf("%d\n", runner());
    return 0;
}

int sum(int num) {
    static int result = 0;
    result += num;
    return result;
}

int summer() {
    printf("%d\n", sum(55));
    printf("%d\n", sum(60));
    printf("%d\n", sum(5));
    return 0;
}

// NOTE: we can also apply "static" to functions. if a function has "static" before it, it's scope is limited to this file rather than being global