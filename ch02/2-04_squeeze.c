#include <stdio.h>

/* Removes all occurances of c from s */
void squeeze_c(char s[], char c);

/* Removes all occurances of characters in s2 from s1 */
void squeeze_s(char s1[], char s2[]);

/* Determines if c is contained within s */
int contains(char s[], char c);

/* Test functions */
void strcopy(char s[], char buff[]);
void test_squeeze_c(char buff[], char s[], char c);
void test_squeeze_s(char buff[], char s1[], char s2[]);

int main()
{
    char buff[100];
    test_squeeze_c(buff, "apples", 'a');
    test_squeeze_c(buff, "apples", 'p');
    test_squeeze_c(buff, "apples", 'l');
    test_squeeze_c(buff, "apples", 'e');
    test_squeeze_c(buff, "apples", 's');
    test_squeeze_c(buff, "apples", 'd');
    test_squeeze_c(buff, "apples;oranges;bananas;", ';');
    test_squeeze_c(buff, "apples;oranges;bananas;", 's');

    test_squeeze_s(buff, "apples", "apples");
    test_squeeze_s(buff, "apples", "apple");
    test_squeeze_s(buff, "apples", "aeiou");

    test_squeeze_s(buff, "I am a slinky fox", " ");
    test_squeeze_s(buff, "I am a slinky fox", "     ");
    test_squeeze_s(buff, "I am a slinky fox", "");
    test_squeeze_s(buff, "I am a slinky fox", "a");
}

void test_squeeze_c(char buff[], char s[], char c)
{
    /* Copy s into modify-able buffer */
    strcopy(s, buff);
    /* Perform squeeze (on the not-read-only buffer) */
    squeeze_c(buff, c);
    /* Print results */
    printf("Squeeze \'%c\' from \"%s\": \"%s\"\n", c, s, buff);
}

void test_squeeze_s(char buff[], char s1[], char s2[])
{
    strcopy(s1, buff);
    squeeze_s(buff, s2);
    printf("Squeeze \"%s\" chars from \"%s\": \"%s\"\n", s2, s1, buff);
}

void strcopy(char s[], char buff[])
{
    int i;
    for (i=0; s[i] != '\0'; ++i)
        buff[i] = s[i];
    buff[i] = '\0';
}

void squeeze_c(char s[], char c)
{
    int i, j;
    for (i=j=0; s[i] != '\0'; ++i) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int contains(char s[], char c)
{
    int i;
    for (i=0; s[i] != '\0'; ++i) {
        if (s[i] == c)
            return 1;
    }
    return 0;
}

void squeeze_s(char s1[], char s2[])
{
    int i, j;
    for (i=j=0; s1[i] != '\0'; ++i) {
        if (!contains(s2, s1[i]))
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
