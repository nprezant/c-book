#include <stdio.h>

#define MAXLINE 25 /* maximum input line length */
#define THRESHOLD 80 /* threshold line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* prints all lines longer than 80 characters */
int main() {

    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline2(char s[], int lim) {

    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
        if (i < lim)
            s[i] = c;
    }

    if (c == '\n' && i < lim) {
        s[i] = c;
        ++i;
    }

    if (i < lim)
        s[i] = '\0';
    else
        s[lim-1] = '\0';

    return i;
}

