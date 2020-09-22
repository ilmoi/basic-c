#include <stdio.h>

 int marrays_cls() {
     // eg here we're declaring a 2d array - first # is row, second is col
     char vowels[1][5] = {
         {'a', 'e', 'i', 'o', 'u'}
     };

     // NOTE - you can skip putting X (compiler will figure it out) but you can't skip putting Y
     char same_vowels[3][5] = {
         {'a', 'e', 'i', 'o', 'u'},
         {'a', 'e', 'i', 'o', 'u'},
         {'a', 'e', 'i', 'o', 'u'}
     };

     printf("%s", vowels);
     printf("%s", same_vowels);
     return 0;
 }

int marrays_exc() {
    int grades[2][5];
    float average;
    int i;
    int j;

    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    int averages[5];

    // for loop to calc the overall average
    for (i = 0; i < 2; i++) {
        average = 0; // per subject
        for (j = 0; j < 5; j++) {
            average += grades[i][j];
        }
        averages[i] = average;
    }
    printf("%s", averages);
    return 0;
}
