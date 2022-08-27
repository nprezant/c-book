#include <stdio.h>

int main() {
    int c, nc;

    nc = 0;
    while ((c = getchar()) != EOF) {
       if (c == '\n' || c == ' ' || c == '\t') {
           ++nc;
       }
    }

    printf("Whitespace: %d characters\n", nc);
}
