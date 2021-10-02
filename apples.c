/*
 * Filename: apples.c
 *
 * Description: Given the number of apples and apples per bag, the program predicts how many whole bags of apples can be produced with leftovers
 *
 * Author: Anushka Kulasekara
 * Date: September 2021
 */



#include <stdio.h>

int main(void) {

    int apls = 0;
    int aplsperbag = 0; 
    int bags = 0;
    int leftovr = 0;
    int result = 0;

//Please, enter the number of apples available and the number of apples each bag holds: 500 12
   printf("Please, enter the number of apples available and the number of apples each bag holds: ");

//While loop to keep prompting the user until they enter Crtl d
   while ( ( result = scanf("%d %d", &apls, &aplsperbag) ) != EOF) {

//Validate the values
    if ( apls <= 0 || aplsperbag <= 0 ){
       
        printf(" %d and %d is an invaild entry. Please try again with positive values above zero.\n ", apls, aplsperbag);
    }

    else {

//Number of apples available => 500, number of apples each bag holds => 12.
        printf("Number of apples available => %d, ", apls);
        printf("number of apples each bag holds => %d. \n", aplsperbag);

//Number of bags produced => 41, number of apples left over => 8.

        bags = apls/aplsperbag;
        leftovr = apls%aplsperbag;

        printf("Number of bags produced => %d, ", bags);
        printf("number of apples left over => %d. \n", leftovr);
        
    }
    
    printf("Please, enter the number of apples available and the number of apples each bag holds: ");

   }
   
    printf( "\nDone.\n");


   return 0;
}
