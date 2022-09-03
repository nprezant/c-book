#include <stdio.h>

#define TABSIZE 8 /* Number of spaces between tab stops */
#define MAXLINE 40 /* Max length of line handled */
#define ENDTABMARK '|' /* Marks the end of a tab. If set to '|', can help visualize tabs */

/* Replace tabs with spaces */

int main() {
    int c, i;

    i = 0;

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            if (i%TABSIZE == 0) { /* on a tab stop */
                putchar(' ');
                ++i;
            }
            for (; i%TABSIZE!=0; ++i) {
                if (i%TABSIZE == TABSIZE - 1)
                    putchar(ENDTABMARK);
                else
                    putchar(' ');
            }
        }
        else {
            if (c == '\n')
                i = 0;
            else
                ++i;
            putchar(c);
        }
    }
}

