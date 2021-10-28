/*
 * Filename: imgops.c
 *
 * Description: Simple operations on images
 *
 * Author: RV
 * Modified by: AL
 *
 * Completed by: Darren Fok
 * Completion Date: October 27, 2021
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

/* Get the value in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

/* Set the pixel at coordinate {x,y} to the specified color. */
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
    // Put your code here.
    memset(array, 0, cols*rows*sizeof(array[0]));
    return;
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
	// Put your code here
  uint8_t* copyImage = malloc(cols*rows*sizeof(array[0]));

  //if allocation fails, return null
  if(copyImage == NULL){
    return NULL;
  }

  else{
    for(unsigned int loop = 0; loop < cols*rows; loop++){
      copyImage[loop] = array[loop];
    }
    return copyImage;
    free(copyImage);
    copyImage = NULL;
  }
}

/* Return the darkest color that appears in the array; 
   i.e. the smallest value.
*/
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	// Put your code here
  uint8_t minimum = array[0];
  for(unsigned int loop = 0; loop < cols*rows; loop++){
    if(array[loop] < minimum){
      minimum = array[loop];
    }
  }
	return minimum;
}

/* Return the lightest color that appears in the array; 
   i.e. the largest value.
*/
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
	// Put your code here
  uint8_t maximum = array[0];
  for(unsigned int loop = 0; loop < cols*rows; loop++){
    if(array[loop] > maximum){
      maximum = array[loop];
    }
  }
	return maximum;
}

/* Replace every instance of pre_color with post_color. */
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
	// Put your code here
  for(unsigned int loop = 0; loop < cols*rows; loop++){
    if(array[loop] == pre_color){
      array[loop] = post_color;
    }
  }
	return;
}

/* Flip the image, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
    // Put your code here
    unsigned int temp;
    unsigned int left = 0;
    unsigned int right = cols-1;
    
    for(unsigned int loop = 0; loop < rows; loop++){
      while(left != right && right > left){
        int first = loop*cols+left;
        int second = loop*cols+right;

        //swap color values
        temp = array[first];
        array[first] = array[second];
        array[second] = temp;

        left++;
        right--;
      }
      //after each row, reset left and right back to the very left and very right positions.
      left = 0;
      right = cols-1;
    }
  
    return;
}

/* Find the first coordinate of the first pixel with a value that
   equals color. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // Put your code here
    for(unsigned int loop1 = 0; loop1 < rows; loop1++){
      for(unsigned int loop2 = 0; loop2 < cols; loop2++){
        if(array[loop1 * cols + loop2] == color){
          *x = loop2;
          *y = loop1;
          return 1; 
        }
      }
    }
    return 0;
}

/* Invert the image, so that black becomes white and vice
   versa, and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // Put your code here
    for(unsigned int loop1 = 0; loop1 < rows; loop1++){
      for(unsigned int loop2 = 0; loop2 < cols; loop2++){
        array[loop1*cols+loop2] = 255 - array[loop1*cols+loop2];
      }
    }
	return;
}
