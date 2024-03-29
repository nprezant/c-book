#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define UPPER 300
#define STEP 20

float to_cels(float fahr);

int main()
{
    int fahr;

    printf("%8s%8s\n", "Fahr", "Celsius");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%8d%8.1f\n", fahr, to_cels(fahr));
}

float to_cels(float fahr) {
    return 5.0 / 9.0 * (fahr - 32);
}
