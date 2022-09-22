#include <stdio.h>

/* for loop from the getline function:
 * for (i=0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 */

#define MAXLINE 1000

int main() {

    int i = 0;
    int c;
    char s[MAXLINE];
    int loop = 1;

    for (i=0; loop; ++i) {

        // Need to break if we are out of line limit bounds or if this is a 
        // new line or EOF.
        if (i >= MAXLINE-1) {
            loop = 0;
        }
        else if ((c = getchar()) != '\n') {
            if (c == EOF)
                loop = 0;
        }
        s[i] = c;
    }

    s[i] = '\0';
    
    printf("%s", s);
}
