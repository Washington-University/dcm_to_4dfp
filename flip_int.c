/*$Header: /opt/cvs/dcm_to_4dfp/flip_int.c,v 1.1 2006/08/25 20:55:49 mohanar Exp $*/

/*
**  FUNCTION: int_flip
**	
**  FUNCTIONAL DESCRIPTION: Convert integer pixel slice
                            to Analyze Coordinant System.
**  RETURN VALUE: none
**	
**  ALGORITHM: Take one slice from a image volume in 4dfp orientation
      and flip the X and Y to 4dint orientation. The Z is reordered 
      in the calling subroutine. The flag must be Analyze "hist.orient".
**	
**  SIDE EFFECTS: Assumption is that incomming data is 4dfp oriented.
**	
*/

#include "include/dicom.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static void errm (char* program) {
	fprintf (stderr, "%s: memory allocation error\n", program);
	exit (-1);
}

void
int_flip(int flag, U16 *img, U16 pnx, U16 pny)
{
	U16	*vector, vecdim;
	U16	ix, iy, index;

	vecdim = pnx*pny;
	
	if (!(vector = (U16 *) malloc (vecdim * sizeof (U16)))){
	    printf(" flag=%d pnx=%d pny=%d\n",flag, pnx, pny);
	    errm ("int_flip");
        }
        
  switch(flag) {
	    
	case 0:		/* Transverse flip Y */
	    for (ix = 0; ix < pnx; ix++) {
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			vector[iy] = img[index];
		  }
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			img[index] = vector[pny - 1 - iy];
		  }
	    }
	    break;

	case 1:		/* Coronal flip Y */
	    for (ix = 0; ix < pnx; ix++) {
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			vector[iy] = img[index];
		  }
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			img[index] = vector[pny - 1 - iy];
		  }
	    }
	    break;

	case 2:		/* Sagittal: flip X and Y */
	    for (iy = 0; iy < pny; iy++) {
		  for (ix = 0; ix < pnx; ix++) {
			index = ix + pnx*iy;
			vector[ix] = img[index];
		  }
		  for (ix = 0; ix < pnx; ix++) {
			index = ix + pnx*iy;
			img[index] = vector[pnx - 1 - ix];
		  }
	    }
			/* flip Y */
	    for (ix = 0; ix < pnx; ix++) {
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			vector[iy] = img[index];
		  }
		  for (iy = 0; iy < pny; iy++) {
			index = ix + pnx*iy;
			img[index] = vector[pny - 1 - iy];
		  }
	    }
	    break;
	 
	default:       /* do nothing */
	    break;
  }

} /* end of int_flip */

