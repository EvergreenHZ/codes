#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 21;
int count[10];
class BigN {
public:
        int digit[MAXN];
        int len;
        BigN(): len(0) {}
        void show() {
                for (int i = len - 1; i >= 0; i--) {
                        printf("%d", digit[i]);
                }
                printf("\n");
        }
};

void double_it(BigN &a, BigN& c) {
        int carry = 0;
        for (int i = 0; i < a.len; i++) {
                int tmp = a.digit[i] * 2 + carry;
                c.digit[c.len++] = tmp % 10;
                carry = tmp / 10;
        }
        if (carry) {
                c.digit[c.len++] = carry;
        }
}

int main() {
        BigN a, c;
        char s[MAXN];
        scanf("%s", s);
        int len = strlen(s);
        for (int i = len - 1; i >= 0;i --) {
                a.digit[a.len++] = s[i] - '0';
                count[s[i] - '0'] ++;
        }

        double_it(a, c);

        for (int i = 0; i < c.len; i++) {
                count[c.digit[i]]--;
        }

        for (int i = 0; i < 10; i++) {
                if (count[i] != 0) {
                        printf("No\n");
                        c.show();
                        return 0;
                }
        }
        printf("Yes\n");
        c.show();
        return 0;
}
