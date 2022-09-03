#include <stdio.h>

#define NONE 0
#define IN_LINE_COMMENT 1
#define IN_MULTI_LINE_COMMENT 2
#define IN_STRING_LITERAL 3
#define IN_CHARACTER_CONSTANT 4

/* removes comments from a c-formatted file.
 * literally just removes the comments and
 * characters directly in the comment.
 * e.g., for the case:
 * >>> int i; // test case counter
 * the line will become "int i; " with the
 * extra space at the end.
 */

int main() {

    int c, pc, state;

    state = NONE;

    while ((c = getchar()) != EOF) {

        if (state == NONE) {
            // Continue until we find something interesting
            if (pc == '/' && c == '/') {
                state = IN_LINE_COMMENT;
            }
            else if (pc == '/' && c == '*') {
                state = IN_MULTI_LINE_COMMENT;
            }
            else if (pc == '/' && (c != '/' || c != '*')) {
                putchar(pc);
                putchar(c);
            }
            else if (c == '\'') {
                state = IN_CHARACTER_CONSTANT;
                putchar(c);
            }
            else if (c == '\"') {
                state = IN_STRING_LITERAL;
                putchar(c);
            }
            else if (c != '/') {
                putchar(c);
            }
        }

        else if (state == IN_LINE_COMMENT) {
            // Wait for newline
            if (c == '\n') {
                putchar(c);
                state = NONE;
            }
        }
        else if (state == IN_MULTI_LINE_COMMENT) {
            // Wait for "*/"
            if (pc == '*' && c == '/') {
                state = NONE;
                pc = c = -1; // Reset to handle cases like /*xxx*//
            }
        }
        else if (state == IN_CHARACTER_CONSTANT) {
            // Wait for "'", watch out for escape sequences
            if (pc != '\\' && c == '\'')
                state = NONE;
            putchar(c);
        }
        else if (state == IN_STRING_LITERAL) {
            // Wait for ", watch out for escape sequences
            if (pc != '\\' && c == '\"')
                state = NONE;
            putchar(c);
        }

        pc = c;
    }
}

