#include <stdio.h>

int arrays_cls() {
     // defines an array of 10 ints
     int numbers[10];

     // populate the array
     numbers[0] = 10;
     numbers[1] = 20;

     printf("the 2nd numbers is %d", numbers[1]);
     return 0;
 }

int arrays_exc() {
    int average;
    int grades[3];

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("Average is %d", average);
    return 0;
}
