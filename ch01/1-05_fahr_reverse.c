
#include <stdio.h>

/* print Fahrenheit-Celsius table in reverse
 * for fahr = 300, 280, ..., 0 */

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    int fahr;

    printf("%8s%8s\n", "Celsius", "Fahr");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%8d%8.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
}
