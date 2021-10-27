/*
 * testDriver.c - Test functions from imgops.c
 * Author: RV - 2014
 * 
 * Modified by: AL - 2021
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] ) {
	
  const unsigned int winwidth  = 400;
  const unsigned int winheight = 400;

  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;

  // initialize the graphics system
  // ********************************************************
  // Get a first window
  draw_startup( (char*)"Window 1", winwidth, winheight );

  uint8_t* img = NULL;

  if( argc == 2 ) // if a filename was specified
  {
    uint32_t depth=0;
    int alpha=0;
    if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
    {
      printf( "failed to load image %s\n", argv[1] );
      exit(1);
    }
  }
  else // no filename specified: create a blank image
  {
    // allocate an array for our image
    img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
    if( img == NULL )
    {
      printf( "failed to allocate memory for image.\n" );
      exit(1);
    }

    // set the whole array to zero (black)
    memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
  }

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );

  // ********************************************************
  // Get a second window
  draw_startup( (char*)"Window 2", winwidth, winheight );

  // Get a copy of original image
  printf( "Image copied\n" );
  uint8_t* img_Inverted = copy( img, imgwidth, imgheight );

  // Flipping the image, left-to-right, like in a mirror.
  printf( "Image inverted\n" );
  invert( img_Inverted, imgwidth, imgheight );

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img_Inverted, imgwidth, imgheight );

  // ********************************************************

  // finalize the graphics system, freeing its resources
  draw_shutdown();

  // every malloc() should have a matching free()
  free(img);
  free(img_Inverted);
  
  // let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  img_Inverted = NULL;
  
  return 0;
}
