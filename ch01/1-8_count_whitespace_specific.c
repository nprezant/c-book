#include <stdio.h>

int main() {
    int c;
    int ns, nt, nn;

    ns = nt = nn = 0;
    while ((c = getchar()) != EOF) {
       if (c == '\n')
           ++nn;
       else if (c == ' ')
           ++ns;
       else if (c == '\t')
           ++nt;
    }

    printf("Whitespace Summary:\n");
    printf("Blanks: %d\n", ns);
    printf("Tabs: %d\n", nt);
    printf("Newlines: %d\n", nn);
}
