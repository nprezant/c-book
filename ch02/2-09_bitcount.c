#include <stdio.h>

/*
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of bitcount.
 *
 * original version of bitcount:
 *
 * bitcount: count 1 bits in x
 * int bitcount(unsigned x)
 * {
 *     int b;
 *     for (b = 0; x != 0; x >>= 1)
 *         if (x & 01)
 *             b++;
 *     return b;
 * }
 *
 * Explanation:
 * What does x-1 do?
 *   x  |  x-1  | bin
 *   ------------------
 *   1  |  0    | 0000
 *   2  |  1    | 0001
 *   3  |  2    | 0010
 *   4  |  3    | 0011
 *   5  |  4    | 0100
 *
 * What does x &= (x-1) do?
 *    x    | x &= (x-1)
 *   -----------------------------
 *   0001  | 0001 & 0000 --> 0000
 *   0010  | 0010 & 0001 --> 0000
 *   0011  | 0011 & 0010 --> 0010
 *   0100  | 0100 & 0011 --> 0000
 *
 * Subtracting 1 from x ensures that the rightmost 1-bit is now a 0, and that
 * all bits further right are now 1s. By joining with a logical &, all of these
 * places (rightmost 1-bit and all 0s to the right on the original x) will become
 * 0s.
 *
 * We can use this to make bitcount more efficient by relying on the fact that
 * x &= (x-1) removes a 1 each time, and that C considers any non-zero value
 * true. So we can x &= (x-1) all day until x is zero.
 */

/* Counts the 1 bits in x */
int bitcount(unsigned x)
{
    int b = 0;
    while (x) {
        x &= (x-1);
        ++b;
    }
    return b;
}

int main()
{
    unsigned x = 0b0101010011001;
    printf("Number of bits in 0101010011001 is %d\n", bitcount(x));
    printf("Number of bits in 01 is %d\n", bitcount(0b01));
    printf("Number of bits in 11 is %d\n", bitcount(0b11));
}
