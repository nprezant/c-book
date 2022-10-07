#include <stdio.h>
#include <string.h>

/* Write a function escape(s,t) that converts characters like newline and
 * tab into visible escape sequences like \n and \t as it copies the string
 * t to s. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 *
 * Assumes that s is big enough.
 */

#define MAXLINE 1000

#define IN_ESCAPE 1
#define NOT_IN_ESCAPE 0

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char s[MAXLINE*2]; // In case all characters are escape sequences
    char t[MAXLINE];

    strcpy(t, "a tab:\t; and now a newline:\n;");
    escape(s, t);
    printf("%s\n", s);

    escape(s, "only tabs:\t\t\t\t\t;");
    printf("%s\n", s);

    escape(s, "only newlines:\n\n\n\n\n;");
    printf("%s\n", s);

    unescape(s, "\\none\\ntwo\\nthree");
    printf("%s\n", s);

    unescape(s, "fruit\\t|count\\n---\\t|---\\napple\\t|5\\noranges\\t|2");
    printf("%s\n", s);

    unescape(s, "bad escape sequence: \"\\\\a\" \\a");
    printf("%s\n", s);
}

void escape(char s[], char t[])
{
    int i, j;
    for (i=0, j=0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j++] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    int state;
    state = NOT_IN_ESCAPE;
    for (i=0, j=0; t[i] != '\0'; ++i) {

        if (state == IN_ESCAPE) {
            switch (t[i]) {
                case '\\':
                    s[j++] = '\\';
                    break;
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    fprintf(stderr,
                            "Unrecognized escape sequence: %c%c\n", t[i-1], t[i]);
                    s[j++] = t[i-1];
                    s[j++] = t[i];
                    break;
            }
            state = NOT_IN_ESCAPE;
        }

        else { // Not in escape sequence
            switch (t[i]) {
                case '\\':
                    state = IN_ESCAPE;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        }
    }
    s[j++] = '\0';
}
