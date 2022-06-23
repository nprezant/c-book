#include <stdio.h>

main() {
    int c;
    while ((c = getchar()) != EOF)
        printf("char() != EOF: %d\n", c != EOF);
    printf("char() != EOF: %d\n", c != EOF);
}
