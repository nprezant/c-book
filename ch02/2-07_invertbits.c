#include <stdio.h>

/* Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others
 * unchanged
 */

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main()
{
    printf("Invert 0000 (0) to 0001 (1): %4x\n", invert(0x0, 0, 1)); 
    printf("Invert 0000 (0) to 0011 (3): %4x\n", invert(0x0, 1, 2)); 
    printf("Invert 0000 (0) to 0111 (7): %4x\n", invert(0x0, 2, 3)); 
    printf("Invert 0000 (0) to 1111 (f): %4x\n", invert(0x0, 3, 4)); 
    printf("Invert 0000 (0) to 1110 (e): %4x\n", invert(0x0, 3, 3)); 
    printf("Invert 0000 (0) to 1100 (c): %4x\n", invert(0x0, 3, 2)); 
    printf("Invert 0000 (0) to 1000 (8): %4x\n", invert(0x0, 3, 1)); 
    printf("Invert 1010 (a) to 0101 (5): %4x\n", invert(0xa, 3, 4)); 
    printf("Invert 0101 (5) to 1010 (a): %4x\n", invert(0x5, 3, 4)); 
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned subset = getbits(x, p, n);
    return setbits(x, p, n, ~subset);
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int rmargin = p+1-n;
    unsigned int mask = ~(~0 << n) << rmargin;
    return x & ~mask | ((y & (mask >> rmargin)) << rmargin);
}
