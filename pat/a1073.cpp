#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int result[1010];

int main() {
        char s[10010];
        scanf("%s", s);
        char *p = strchr(s, 'E');
        int exp = 0;
        sscanf(p + 1, "%d", &exp);

        if (s[0] == '-') printf("-");

        if (exp < 0) {
                printf("0.");
                for (int i = 0; i < -exp - 1; i++)
                        printf("0");
                char *q = s + 1;
                while (q != p) {
                        if (*q != '.') printf("%c", *q);
                        q++;
                }
        } else if (exp > 0) {
                char *q = s + 1;
                int accurate_digit_num = p - s - 3;
                printf("%c", s[1]);
                char *r = q + 2;
                int i = 0;
                if (exp >= accurate_digit_num) {
                        for (; i < accurate_digit_num; i++) {
                                printf("%c", *(r + i));
                        }
                        for (; i < exp; i++) {
                                printf("0");
                        }
                } else {
                        for (; i < exp; i++) {
                                printf("%c", *(r + i));
                        }
                        printf(".");
                        for (; i < accurate_digit_num; i++) {
                                printf("%c", *(r + i));
                        }
                }
        }
        cout << endl;
        return 0;
}
