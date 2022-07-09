#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
       if (c == '\n')
           printf("\\n\n");
       else if (c == '\t')
           printf(" -> ");
       else
           putchar(c);
    }
}
