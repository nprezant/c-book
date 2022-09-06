#include <stdio.h>

#define BUFFSIZE 100 /* max line length read at a time */
#define MAXCOLUMN 30 /* lines longer than this will be folded */
#define MINBREAK (MAXCOLUMN / 2) /* auto-inserted breaks will be after this */

int getline_(char line[], int lim);
int fold_(char line[]);
int strlen_(char line[]);
void print_until(char s[], int until);
int substr_(char line[], int start_at);
int min(int, int);

int main() {
    int len, i;
    char buff[BUFFSIZE];

    /* Read into the buffer. Stop at a newline,
     * or at the buffer size limit. If a line is
     * longer than the buffer, you'll get it on
     * the next time around
     */
    while ((len = getline_(buff, BUFFSIZE)) > 0) {

        /* Fold this line. If a fold happened
         * and there is still more line left,
         * keep folding the leftover parts
         */
        while ((len = fold_(buff)) > 0) {
            // Keep on folding
        }
    }
}

int strlen_(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

int fold_(char line[])
{
    int i, len;

    len = strlen_(line);

    /* Just print the line if we're able */
    if (len < MAXCOLUMN) {
        printf("%s", line);
        return 0;
    }

    /* Insert a newline at the nearest space to the
     * column break
     */
    for (i = min(len, MAXCOLUMN); i > MINBREAK && line[i] != ' ' && line[i] != '\t'; --i) {
        /* this just finds where to insert the column break */
    }

    if (i > MINBREAK) {
        line[i] = '\n';
        print_until(line, i + 1);
        len = substr_(line, i + 1);
        return len;
    }

    /* If there is no space to be had, hyphenate */
    else {
        print_until(line, MAXCOLUMN - 1);
        printf("-\n");
        len = substr_(line, MAXCOLUMN - 1);
        return len;
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

void print_until(char s[], int until) {
    char c = s[until];
    s[until] = '\0';
    printf("%s", s);
    s[until] = c;
}

int substr_(char line[], int start_at) {

    int i;

    for (i = 0; line[start_at + i - 1] != '\0'; ++i) {
        line[i] = line[start_at + i];
    }

    return i;
}

int getline_(char s[], int lim) {

    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
