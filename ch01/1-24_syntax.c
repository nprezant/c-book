#include <stdio.h>

#define MAXNESTDEPTH 100 /* Maximum amount of nesting handled */
#define OPEN_BRACES  "[({<"
#define CLOSE_BRACES "])}>"
#define AMBIGUOUS "\"\'"
#define BRACES (OPEN_BRACES CLOSE_BRACES)

#define BUFFSIZE 2

#define STATE_NONE 0
#define STATE_IN_LINE_COMMENT 1
#define STATE_IN_MULTI_LINE_COMMENT 2
#define STATE_IN_STRING_LITERAL 3
#define STATE_IN_CHARACTER_CONSTANT 4

/* Checks for unmatched braces
 */

int indexof(char c, char list[]);
int contains(char c, char list[]);
int isbrace(char);
int isopenbrace(char);
int isclosebrace(char);
int isambiguous(char);
int ismatchingambiguous(char open, char close);
int ismatchingbrace(char open, char close);
int getnextcodechar();

int nl; /* tracks current line number */
int buff[BUFFSIZE]; /* current character and one ahead */
int state = STATE_NONE; /* tracks current state */

int main() {

    int c;
    int depth;
    char braces[MAXNESTDEPTH];
    extern int nl; /* line number */

    depth = 0;
    nl = 1; /* line counting starts at 1 */

    while ((c = getnextcodechar()) != EOF) {

        if (!isbrace(c) && !isambiguous(c)) continue;

        if (isopenbrace(c) || (isambiguous(c) && braces[depth-1] != c)) {
            braces[depth] = c;
            ++depth;
        }

        else if (isclosebrace(c) || isambiguous(c)) {
            if (depth == 0) {
                printf(
                    "Syntax error (line %d)."
                    " Closing token \'%c\' found with no matching"
                    " open token.\n", nl, c);
            }
            else if (
                    ismatchingbrace(braces[depth-1], c)
                    || ismatchingambiguous(braces[depth-1], c)) {
                --depth;
                braces[depth] = '\0';
            }
            else {
                printf(
                    "Syntax error (line %d)."
                    " Expected closing token for \'%c\',"
                    " but got \'%c\'.\n", nl, braces[depth-1], c);
            }
        }
    }

    if (depth != 0) {
        printf(
            "Syntax error (line %d)."
            " EOF reached and closing token(s) not found"
            " for %s.\n", nl, braces);
    }
}

int readfuture(int c[2]) {
    c[0] = c[1];
    c[1] = c[1] != EOF ? getchar() : EOF;
    return c[0];
}

int getnextcodechar() {
    extern int buff[BUFFSIZE];
    extern int state;
    extern int nl;

    int justclosedstring = 0;

    /* Need to determine if this is a character
     * worth returning or not. If we are inside
     * a string literal or comment or character
     * constant then we should not return it.
     * Otherwise we should.
     */

    while (readfuture(buff) != EOF) {

        if (buff[0] == '\n') ++nl;

        /* Determine current state */
        if (state == STATE_NONE) {

            if (buff[0] == '/' && buff[1] == '/')
                state = STATE_IN_LINE_COMMENT;
            else if (buff[0] == '/' && buff[1] == '*')
                state = STATE_IN_MULTI_LINE_COMMENT;
            else if (buff[0] == '/' && (buff[1] != '/' && buff[1] != '*'))
                state = STATE_NONE;
            else if (!justclosedstring && buff[0] == '\'')
                state = STATE_IN_CHARACTER_CONSTANT;
            else if (!justclosedstring && buff[0] == '\"')
                state = STATE_IN_STRING_LITERAL;

            justclosedstring = 0;

            /* Return the character unless we have just opened
             * a comment
             */
            if (
                state == STATE_NONE
                || state == STATE_IN_CHARACTER_CONSTANT
                || state == STATE_IN_STRING_LITERAL
            )
                return buff[0];

        }

        /* Don't return anything while in a comment */
        else if (state == STATE_IN_LINE_COMMENT) {
            if (buff[0] == '\n')
                state = STATE_NONE;
        }

        /* Don't return anything while in a comment */
        else if (state == STATE_IN_MULTI_LINE_COMMENT) {
            if (buff[0] == '*' && buff[1] == '/') {
                state = STATE_NONE;
                buff[0] = buff[1] = -1; // Reset to handle cases like /*xxx*//
            }
        }

        /* Don't return anything while inside a character constant */
        else if (state == STATE_IN_CHARACTER_CONSTANT) {
            if (buff[0] != '\\' && buff[1] == '\'') {
                state = STATE_NONE;
                justclosedstring = 1;
            }
        }

        /* Don't return anything while inside string literals */
        else if (state == STATE_IN_STRING_LITERAL) {
            if (buff[0] != '\\' && buff[1] == '\"') {
                state = STATE_NONE;
                justclosedstring = 1;
            }
        }
    }

    return buff[0]; /* EOF */
}

/* Index of `c` in `list'.
 * -1 if not found
 */
int indexof(char c, char list[]) {
    int i;
    for (i=0; list[i] != '\0'; ++i) {
        if (c == list[i])
            return i;
    }
    return -1;
}

int contains(char c, char list[]) {
    return indexof(c, list) != -1;
}

int isbrace(char c) {
    return contains(c, BRACES);
}

int isopenbrace(char c) {
    return contains(c, OPEN_BRACES);
}

int isclosebrace(char c) {
    return contains(c, CLOSE_BRACES);
}

int isambiguous(char c) {
    return contains(c, AMBIGUOUS);
}

int ismatchingambiguous(char open, char close) {
    int i, j;
    i = indexof(open, AMBIGUOUS);
    j = indexof(close, AMBIGUOUS);
    return i == j && i != -1;
}

int ismatchingbrace(char open, char close) {
    int i, j;
    i = indexof(open, OPEN_BRACES);
    j = indexof(close, CLOSE_BRACES);
    return i == j && i != -1;
}
