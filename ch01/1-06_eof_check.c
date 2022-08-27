#include <stdio.h>

main() {
    int c;
    printf("EOF = %d\n", EOF);
    while ((c = getchar()) != EOF)
        printf("c = %c (%d), char() == EOF: %d\n", c, c, c == EOF);
    printf("c = %c (%d), char() == EOF: %d\n", c, c, c == EOF);
}
