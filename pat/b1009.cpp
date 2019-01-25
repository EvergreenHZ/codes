#include "../include/common.h"

void reverse_words(char *s) {
        char *p = strchr(s, ' ');
        if (p == NULL) {
                printf("%s\n", s);
        } else {
                *p = '\0';
                p = p + 1;
                reverse_words(p);
                printf("%s\n", s);
        }
}

void reverse_words_v2(char *s, char *m) {
        char *p = strchr(s, ' ');
        if (p == NULL) {
                printf("%s ", s);
        } else {
                *p = '\0';
                p = p + 1;
                reverse_words_v2(p, m);
                if (s == m) {
                        printf("%s", s);
                } else {
                        printf("%s ", s);
                }
        }
}

int main()
{
        char s[100];
        fgets(s, 81, stdin);
        *(strchr(s, '\n')) = '\0';
        //printf("%s\n", s);

        reverse_words_v2(s, s);
        printf("\n");
}
