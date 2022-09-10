#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Print the size limits of various data types */

int main() {

    /* Not really sure about the way to determine max sizes
     * by direct computation that will work with any c implementation.
     * Except maybe sizeof, but that hasn't been discussed at this point
     * in the book.
     */

    printf("Int:\n\tmin=%d,\n\tmax=%d\n", INT_MIN, INT_MAX);
    printf("Unsigned Int:\n\tmin=%d,\n\tmax=%d\n", 0, UINT_MAX);

    printf("Short:\n\tmin=%d,\n\tmax=%d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Short:\n\tmin=%d,\n\tmax=%d\n", 0, USHRT_MAX);

    printf("Long:\n\tmin=%ld,\n\tmax=%ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned Long:\n\tmin=%d,\n\tmax=%ld\n", 0, ULONG_MAX);

    printf("Long Long:\n\tmin=%lld,\n\tmax=%lld\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned Long Long:\n\tmin=%d,\n\tmax=%lld\n", 0, ULLONG_MAX);

    printf("Char:\n\tmin=%d,\n\tmax=%d\n", CHAR_MIN, CHAR_MAX);

    printf("Float:\n\tmin=%g,\n\tmax=%g\n", FLT_MIN, FLT_MAX);
    printf("Double:\n\tmin=%g,\n\tmax=%g\n", DBL_MIN, DBL_MAX);
}
