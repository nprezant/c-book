#include <stdio.h>

/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

/* setbits: return x with the n bits that begin at position p set to the rightmost
 * n bits of y, all other bits unchanged
 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned int i;

    printf("Change 0000 (0) to 0110 (6): %4x\n", setbits(0x0, 2, 2, 0x3)); 
    printf("Change 1000 (8) to 1001 (9): %4x\n", setbits(0x8, 0, 1, ~0)); 
    printf("Change 1000 (8) to 1001 (9): %4x\n", setbits(0x8, 3, 4, 0x9)); 
    printf("Change 1000 (8) to 1001 (9): %4x\n", setbits(0x8, 7, 8, 0x9)); 
    printf("Change 1111 (f) to 1001 (9): %4x\n", setbits(0xf, 2, 2, 0x0));
    printf("Change 1111 (f) to 1001 (9): %4x\n", setbits(0xf, 2, 2, ~0 << 2));
    printf("Change 1111 (f) to 1000 (8): %4x\n", setbits(0xf, 2, 3, ~0 << 3));
    printf("Change 1111 (f) to 0001 (1): %4x\n", setbits(0xf, 3, 3, ~0 << 3));
    printf("Change 1111 (f) to 1001 (9): %4x\n", setbits(0xf, 3, 4, 0x9));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /* ~0 << n       : Gets the right number of 0s, right-aligned
     * ~()           : Swaps 1s and 0s, now have right number of 1s, right aligned
     * ~() << p+1-n  : Shifts 1s left to the correct location
     * Example:
     *    p = 3
     *    n = 2
     *    ~0 << n      : 11111100
     *    ~()          : 00000011
     *    ~() << p+1-n : 00001100
     */
   unsigned int mask = ~(~0 << n) << p+1-n;

   /* Combine all of x except for the part to be replaced with
    * the rightmost n portion of y
    */
   return x & ~mask | ((y & (mask >> p+1-n)) << p+1-n);
}
