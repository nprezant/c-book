#include <stdio.h>

/* Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions
 */

unsigned rightrot(unsigned x, int n);
unsigned rightrot_verbose(unsigned x, int n);
void printbits(unsigned x, int n);

int main()
{
    printf("Right rotate 1000 (8) to 0100 (4): %4x\n", rightrot(0x8, 1)); 
    rightrot_verbose(0x8, 1);
    rightrot_verbose(0b011001, 2);
    rightrot_verbose(~(~(unsigned)0 << 6), 2);
}

/* Prints the rightmost n bits of x */
void printbits(unsigned x, int n)
{
    for(--n; n >= 0; --n){
        if (x & 1 << n)
            printf("1");
        else
            printf("0");
    }
}

unsigned rightrot(unsigned x, int n)
{
    // e.g. 11111111
    unsigned max = ~(unsigned)0;

    // Number of bits is the number of times you
    // can divide the maximum number (all bits 1s)
    // by two.
    int nbits;
    for (nbits = 1; (max *= 0.5) >= 1; ++nbits) {
    }

    // Split up the bits to move into two groups:
    // left side 1s: bits to shift right.
    // right side 0s: bits to wrap around to the other side.
    // e.g. 11111100
    unsigned mask = ~(unsigned)0 << n;

    // Take left part of x and move it right
    // Take the displaced part and stick it
    // on the left side.
    unsigned lhs = (x & mask) >> n;
    unsigned rhs = (x & ~mask) << nbits-n;
    return lhs | rhs;
}

unsigned rightrot_verbose(unsigned x, int n)
{
    char lpad[] = "  ";
    char s[80]; // print buffer
    printf("Verbose right-rotating %#x by %d places\n", x, n);

    // Number of bits is the number of times you
    // can divide the maximum number (all bits 1s)
    // by two.
    unsigned max = ~(unsigned)0;
    int nbits;
    for (nbits = 1; (max *= 0.5) >= 1; ++nbits) {
    }

    // Initial values
    printf("%s%-25s: %d\n", lpad, "nbits", nbits); 
    sprintf(s, "x = %#x", x);
    printf("%s%-25s: ", lpad, s); printbits(x, nbits); printf("\n"); 
    printf("%s%-25s: ", lpad, "a = ~(unsigned)0"); printbits(~(unsigned)0, nbits); printf("\n"); 

    // Split up the bits to move into two groups:
    // left side 1s: bits to shift right.
    // right side 0s: bits to wrap around to the other side.
    // e.g. 11111100
    unsigned mask = ~(unsigned)0 << n;

    sprintf(s, "mask = (a) << %d", n);
    printf("%s%-25s: ", lpad, s); printbits(mask, nbits); printf("\n"); 

    unsigned lhs = (x & mask) >> n;
    sprintf(s, "lhs = (x & mask) >> %d", n);
    printf("%s%-25s: ", lpad, s); printbits(lhs, nbits); printf("\n"); 

    unsigned rhs = (x & ~mask) << nbits-n;
    sprintf(s, "rhs = (x & ~mask) << %d", nbits-n);
    printf("%s%-25s: ", lpad, s); printbits(rhs, nbits); printf("\n"); 

    unsigned ret = lhs | rhs;
    sprintf(s, "lhs | rhs", nbits-n);
    printf("%s%-25s: ", lpad, s); printbits(ret, nbits); printf("\n"); 

    return ret;
}

