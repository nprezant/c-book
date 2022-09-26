#include <stdio.h>
#include <ctype.h>

#define BUFFSIZE 1000

/* Converts hexadecimal string to an integer */
int htoi(char s[]);

int trimtrailing(char s[], int len);
int getline_(char s[], int lim);

int main() {

    int len, i;
    char buff[BUFFSIZE];

    while ((len = getline_(buff, BUFFSIZE)) > 0) {
        trimtrailing(buff, len);
        printf(
                "Converted \"%s\" in hexadecimal to %d\n",
                buff,
                htoi(buff));
    }

}

int htoi(char s[]) {
    int i, n;

    /* Handle whitespace */
    for (i=0; s[i]==' ' || s[i]=='\t'; ++i) {}

    /* Handle possibility of optional 0x or 0X */
    if (s[i]=='0' && tolower(s[i+1])=='x')
        i += 2;

    /* Parse hex number. Ignores non-hex characters */
    for (n=0; isdigit(s[i]) || 'a' <= tolower(s[i]) && tolower(s[i]) <= 'f'; ++i) {
        n *= 16;
        if (isdigit(s[i]))
            n += s[i] - '0';
        else
            n += 10 + tolower(s[i]) - 'a';
    }
    return n;
}

int trimtrailing(char s[], int len) {
    while(len>0 && (s[len-1]==' ' || s[len-1]=='\t' || s[len-1]=='\n')) {
        --len;
    }
    s[len] = '\0';
    return len;
}

int getline_(char s[], int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
