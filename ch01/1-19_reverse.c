#include <stdio.h>

#define MAXLINE 40

int getline_(char line[], int maxline);
void reverse(char s[]);
int len(char s[]);
void rstrip(char s[], char c);

int main() {
    char line[MAXLINE];

    while (getline_(line, MAXLINE) > 0) {
        rstrip(line, '\n');
        reverse(line);
        printf("%s\n", line);
    }
}

int getline_(char s[], int lim) {

    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n' && i < lim-1; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

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

