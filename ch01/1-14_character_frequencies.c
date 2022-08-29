#include <stdio.h>

#define N_CHARACTERS ('z'-'a' + 1)
#define IN 0
#define OUT 1

int main() {
    int i, j, c, nc, state;
    int frequencies[N_CHARACTERS] = {0};

    nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c <= 'Z' && c >= 'A')
            ++frequencies[c - 'A'];
        else if (c <= 'z' && c >= 'a')
            ++frequencies[c - 'a'];
    }

    // Horizontal bar chart
    for (i=0; i<N_CHARACTERS; ++i) {
        printf("%4c | ", i+'a');
        for (j=0; j<frequencies[i]; ++j)
            printf("x");
        printf("\n");
    }
}
