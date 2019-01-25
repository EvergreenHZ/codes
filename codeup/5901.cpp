#include "../include/common.h"

bool isPalindrome(const char* s, int n) {
        int b = 0, e = n - 1;
        for (; b < e; b++, e--) {
                if (s[b] != s[e]) {
                        return false;
                }
        }
        return true;
}

int main()
{
        char s[257];
        fgets(s, 257, stdin);
        int i = 0;
        for (; s[i] != '\n'; i++) {
        }
        s[i] = '\0';

        if (isPalindrome(s, i)) {
                printf("YES\n");
        } else {
                printf("NO\n");
        }
}
