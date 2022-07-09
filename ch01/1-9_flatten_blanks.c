#include <stdio.h>
#include <stdbool.h>

int main() {
    int c;
    bool prev_is_blank;

    prev_is_blank = false;
    while ((c = getchar()) != EOF) {
       if (c != ' ') {
          putchar(c);
          prev_is_blank = false;
       }
       else {
           if (!prev_is_blank) {
               putchar(c);
           }
           prev_is_blank = true;
       }
    }
}
