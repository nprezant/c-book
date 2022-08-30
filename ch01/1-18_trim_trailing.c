#include <stdio.h>

#define MAXLINE 40

int getline2(char line[], int maxline);
int trimright(char s[], int len);
int min(int, int);

/* trim any trailing whitespace
 * and any blank lines */
int main() {
    int nc;
    char line[MAXLINE];

    while ((nc = getline2(line, MAXLINE)) > 0) {
        nc = trimright(line, min(nc, MAXLINE));
        if (nc < 1)
            continue;
        printf("%s\n", line);
    }
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

int trimright(char s[], int len) {
    while(len>0 && (s[len-1]==' ' || s[len-1]=='\t' || s[len-1]=='\n')) {
        --len;
    }
    s[len] = '\0';
    return len;
}

int min(int a, int b) {
    return a < b ? a : b;
}
