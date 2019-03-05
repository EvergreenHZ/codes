#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 11;
char N1[MAXN], N2[MAXN];

int get_num(char c) {
        if (c >= '0' && c <= '9')
                return c - '0';
        if (c >= 'a' && c <= 'z')
                return c - 'a' + 10;
}

long long converse_to_base10(char *digit, int base, int len) {
        long long sum = 0;
        for (int i = 0; i < len; i++) {
                sum *= base;
                sum += get_num(digit[i]);
        }
        return sum;
}

int main() {
        int tag, radix;
        scanf("%s%s%d%d", N1, N2, &tag, &radix);
        int len1 = strlen(N1);
        int len2 = strlen(N2);
        if (tag == 2) swap(N1, N2);

        bool flag = false;
        long long x = converse_to_base10(N1, radix, len1);
        long long y = converse_to_base10(N2, radix, len2);
        //cout << x << " : " << y << endl;
        if (x == y) {
                printf("%d\n", radix);
                return 0;
        }
        else {
                for (int i = 2; i <= 36; i++) {
                        long long yy = converse_to_base10(N2, i, len2);
                        if (yy == x) {
                                flag = true;
                                radix = i;
                                break;
                        }
                }
        }
        if (flag) {
                printf("%d\n", radix);
        } else {
                printf("Impossible\n");
        }
        return 0;
}
