//
// Created by Ilja Moisejevs on 8/15/20.
//

#include <stdio.h>

int cond_cls() {
    int foo = 1;
    int bar = 2;
    int moo = 3;

    // standard if / elif / else
    if (foo < bar) {
        printf("foo is smaller than bar.");
    } else if (foo == bar) {
        printf("foo is equal to bar.");
    } else {
        printf("foo is greater than bar.");
    }

    // 2 operators at the same time
    if (foo < bar && moo > bar) {
        printf("foo is smaller than bar AND moo is larger than bar.");
    }

    if (foo < bar || moo > bar) {
        printf("foo is smaller than bar OR moo is larger than bar.");
    }

    return 0;
}

void cond_exc(int guess) {
    if (guess == 555) {
        printf("yay you guessed it!");
    } else if (guess < 555) {
        printf("too low buddy");
    } else {
        printf("too high buddy");
    }
}