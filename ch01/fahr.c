#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    int fahr;

    printf("%s\t%s\n", "Fahr", "Celsius");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
}
