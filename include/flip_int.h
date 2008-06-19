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


void int_flip(int flag, U16 *img, U16 pnx, U16 pny);


