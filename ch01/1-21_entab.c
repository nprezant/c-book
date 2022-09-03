#include <stdio.h>

#define TABSIZE 8 /* Number of spaces between tab stops */

/* replace blank horizontal space with tabs */

void putchars(char c, int count);

int main() {
    int c; /* current character */
    int i; /* column index of current sequence */
    int sequence; /* number of whitespaces in a row */

    i = sequence = 0;

    while ((c = getchar()) != EOF) {

        if (c == ' ') {
            ++sequence;
        }

        else if (c == '\t') {
            sequence +=
                (i+sequence)%TABSIZE == 0
                ? TABSIZE
                : TABSIZE-(i+sequence)%TABSIZE;
        }

        else {
            if (sequence != 0) {
                /* Fill all space possible with tabs.
                 * Note that distance to next tabstop
                 * is i%TABSIZE. First we get the cursor
                 * to the next tabstop, then we repeat tabs
                 * as many times as we are able. */
                if (sequence != 1 && sequence >= TABSIZE-i%TABSIZE && i%TABSIZE != 0) {
                    putchar('\t');
                    sequence -= TABSIZE-i%TABSIZE;
                    i += TABSIZE-i%TABSIZE;
                }
                while (sequence >= TABSIZE) {
                    putchar('\t');
                    sequence -= TABSIZE;
                    i += TABSIZE;
                }
                putchars(' ', sequence); /* Fill extra with spaces */
                i += sequence;
                sequence = 0;
            }
            putchar(c);
            ++i;
        }

        if (c == '\n') {
            i = 0;
        }
    }
}

void putchars(char c, int count) {
    for (; count>0; --count)
        putchar(c);
}

