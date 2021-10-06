/*
 * Filename: reverse.c
 *
 * Description: Takes the integers inputted by the user and reverse the order of those integers
 *
 * Author: Anushka Kulasekara
 * Date: October 6, 2021
 */



#include <stdio.h>

int main(void) {


    const unsigned int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE];
    int inc = 0;
    int rev = 0;


    //Please, enter 10 integers then press Enter: 1 2 3 4 5 6 7 8 9 10

    printf("Please, enter 10 integers then press Enter: ");
    
    //Stores the user input into 10 intergers in the array
    for( unsigned int inc = 0; inc < ARRAY_SIZE; inc++) {
        scanf("%d", &intArray[inc]);
    }
    
    //Content of array before reversing:
    printf("Content of array before reversing: ");
    
    for( unsigned int inc = 0; inc < ARRAY_SIZE; inc++) {
        printf("%d ", intArray[inc]);
    }
    
    //Reversing the array using temp and swapping the intergers
    for ( inc = ARRAY_SIZE - 1; inc > rev; inc--, rev++) {

        int temp = intArray[inc];
        intArray[inc] = intArray[rev];
        intArray[rev] = temp;

    }

    //Content of array after reversing:
    printf("\nContent of array after reversing: ");

    for( unsigned int inc = 0; inc < ARRAY_SIZE; inc++) {
        printf("%d ", intArray[inc]);
    }


    return 0;
}