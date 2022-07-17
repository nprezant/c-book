#include <stdio.h>

#define IN 1
#define OUT 2

int main() {
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
}
