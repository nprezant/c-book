#include <stdio.h>

/* A function which returns the first location in string s1 where any
 * character from the string s2 occurs, or -1 if s1 contains no characters
 * from s2. (Similar to standard library function strpbrk, which returns a
 * pointer to the location.)
 */
int any(char s1[], char s2[]);

void test(char s1[], char s2[])
{
    printf(
        "Within \"%s\", the first location of any of \"%s\" is %d\n",
        s1, s2, any(s1, s2));
}

int main()
{
    test("apples", "a");
    test("apples", "p");
    test("apples", "l");
    test("apples", "e");
    test("apples", "s");
    test("apples", "z");

    test("apples", "abcd");
    test("apples", "efgh");
    test("apples", "zzzzs");
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i=0; s1[i]!='\0'; ++i) {
        for (j=0; s2[j]!='\0'; ++j) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}
