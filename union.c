//
// Created by Ilja Moisejevs on 8/16/20.
//

#include <stdio.h>

typedef union Coins {
    //so union here is the same as MyPy in python - either or. This allows you to save memory if you're not going to be using all the below ones AT THE SAME TIME
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    };
    int coins[4];
} cc;

void get_coins() {
    cc change;
    int i;
    for (i=0 ; i < sizeof(change) / sizeof(int); i++) {
        scanf("%i", change.coins + i);
    }

    printf("there are\n %i quarters\n %i dimes\n %i nickels\n %i pennies\n",
           change.quarter, change.dime, change.nickel, change.penny);
}

typedef union TwentyOne {
    int ints[6];
    char chars[21];
} twon;

void unions_exc() {
    twon mytwon = {1,2,3,4,5,6};
    for (int i=0; i<6; i++) {
        printf("%d\n", mytwon.ints[i]);
    }
    for (int i=0; i<21; i++) {
        printf("%d\n", mytwon.chars[i]);
    }
}
