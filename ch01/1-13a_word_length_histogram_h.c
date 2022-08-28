#include <stdio.h>

#define MAX_WORD_LENGTH 10
#define IN 0
#define OUT 1

int main() {
    int i, j, c, nc, state;
    int lengths[MAX_WORD_LENGTH] = {0};

    nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
       if (c == ' ' || c == '\t' || c == '\n') {
           if (nc > 0) {
               ++lengths[nc < MAX_WORD_LENGTH ? nc - 1 : MAX_WORD_LENGTH - 1];
           }
           state = OUT;
           nc = 0;
       }
       else {
           state = IN;
           ++nc;
       }
    }

    // Horizontal bar chart
    
    // Max instance count
    nc = 0;
    for (i=0; i<MAX_WORD_LENGTH; ++i) {
        if (lengths[i] > nc)
            nc = lengths[i];
    }
    printf("Max count: %d\n", nc);

    // Body
    for (i=0; i<MAX_WORD_LENGTH; ++i) {
        printf("%4d | ", i+1);
        for (j=0; j<lengths[i]; ++j)
            printf("x");
        printf("\n");
    }
}
