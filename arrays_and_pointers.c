//
// Created by Ilja Moisejevs on 8/16/20.
//

#include <stdio.h>
#include <stdlib.h>

void print_array() {
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = &vowels;
    int i;

    for (i=0; i<5; i++) {
        printf("address directly is %u\n", &vowels[i]); //normal deref
        printf("address directly is %u\n", vowels+i); //array name = address of first element
        printf("address through pointer is %u\n", &(pvowels[i]));
        printf("address through pointer is %u\n", pvowels+i);
        printf("value directly is %d\n", vowels[i]); //normal access
        printf("value directly is %d\n", *(vowels+i)); //first getting address, then deref
        printf("value through pointer is %d\n", pvowels[i]);
        printf("value through pointer is %d\n", *(pvowels+i));
    }
}

void print_double_array() {
    int nrows = 2;
    int ncols = 3;
    int i, j;

    // allocate mem for nrows POINTERS
    //** means pointer to pointer I guess
    char **pvowels = (char **) malloc(nrows * sizeof(char *));

    // for each row allocate mem for ncols elements
    pvowels[0] = (char *) malloc(ncols * sizeof(char));
    pvowels[1] = (char *) malloc(ncols * sizeof(char));

    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    for (i = 0; i < nrows; i++) {
        for(j = 0; j < ncols; j++) {
            printf("%c ", pvowels[i][j]);
        }

        printf("\n");
    }

    // Free individual rows
    free(pvowels[0]);
    free(pvowels[1]);

    // Free the top-level pointer
    free(pvowels);
}


void parrays_exc() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
    char **pnumbers;

    /* TODO: complete the following line to allocate memory for holding three rows */
    pnumbers = (int **) malloc(3 * sizeof(int *));

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = (int *) malloc(1 * sizeof(int));
    pnumbers[1] = (int *) malloc(2 * sizeof(int));
    pnumbers[2] = (int *) malloc(3 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    /* TODO: free the top-level pointer */
    free(pnumbers);


}