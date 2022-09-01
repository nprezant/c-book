#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
       if (c == '\n')
           printf("\\n\n");
       else if (c == '\t')
           printf("\\t");
       else if (c == ' ')
           putchar('`');
       else
           putchar(c);
    }
}
