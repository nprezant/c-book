#include <stdio.h>

#define MAXLINE 40

int getline2(char line[], int maxline);
void reverse(char s[]);
int len(char s[]);
void rstrip(char s[], char c);

int main() {
    char line[MAXLINE];

    while (getline2(line, MAXLINE) > 0) {
        rstrip(line, '\n');
        reverse(line);
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

void reverse(char s[]) {
    char tmp;
    int n, l;
    l = len(s) - 1;
    for (n = 0; n <= l / 2; ++n) {
        tmp = s[n];
        s[n] = s[l-n];
        s[l-n] = tmp;
    }
}

int len(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

void rstrip(char s[], char c) {
    int i;
    i = len(s) - 1;
    while (i > 0 && s[i] == c) {
        s[i] = '\0';
        --i;
    }
}

