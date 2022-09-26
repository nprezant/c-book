#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n);

/* print the rightmost n bits of x */
void printbits(unsigned x, int n);

/* print a table row */
void printrow_d(unsigned x);
void printrow_ds(unsigned x, char s[]);

/*
#define _G2(B, A_T, B_T1, B_T1_FN, B2_T, B2_T_FN) \
    A_T: _Generic((B), \
        B_T1: B_T1_FN, \
        B_T2: B_T2_FN)

#define printrow(a,b) _Generic((a), \
    _G2(b,int,int,multiply_ii,double,multiply_id), \
    _G2(b,double,int,multiply_di,double,multiply_dd) ) (a,b)
*/

int main()
{
    unsigned int i;

    // Print out 0-15
    printf("%12s%12s%12s%12s\n", "uint", "hex", "binary", "source");
    for (i=0; i<16; ++i) {
        printrow_d(i);
    }

    // Print out some bit shifted values
    printf("\n");
    printrow_ds(1 << 0, "1 << 0");
    printrow_ds(1 << 1, "1 << 1");
    printrow_ds(1 << 2, "1 << 2");
    printrow_ds(10 << 0, "10 << 0");
    printrow_ds(10 << 1, "10 << 1");

    // Print out some ~0 related values
    printf("\n");
    printrow_ds(0, "0");
    printrow_ds(~0, "~0");
    printrow_ds(~~0, "~~0");
    printrow_ds(~0 << 2, "~0 << 2");
    printrow_ds(~(~0 << 2), "~(~0 << 2)");
    printrow_ds(~(~0 << 2) << 4, "~(~0<<2)<<4");

    // Print out some mask values
    printf("\n");
    printrow_ds(1 & 1, "1 & 1");
    printrow_ds(0 & 0, "0 & 0");
    printrow_ds(1 & 0, "1 & 0");
    printrow_ds(~0 & 3, "~0 & 3");
}

void printrow_d(unsigned x)
{
    printrow_ds(x, "");
}

void printrow_ds(unsigned x, char s[])
{
    printf("%12d%12x", x, x);
    printf("%4s", ""); // padding for the printbits command
    printbits(x, 7);
    printf("%12s", s);
    printf("\n");
}

void printbits(unsigned x, int n)
{
    /* Count down for each bit index to look at */
    for(; n >= 0; n--){
        /* 1 << n is a mask that puts a 1 at our current index
         * and zeros everywhere else.
         *     E.g. 1 << 3 is 1000.
         * By using x & mask we are able to get just the value
         * that the mask lets through. If it is a 1, it is true.
         */
        if (x & 1 << n)
            printf("1");
        else
            printf("0");
    }
}


unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
