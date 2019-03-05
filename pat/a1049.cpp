#include <cstdio>
#include <iostream>
using namespace std;

int count = 0;

//inline void count_ones(int x) {
//        do {
//                if (x % 10 == 1)
//                        count ++;
//                x /= 10;
//        } while (x);
//}
//
//int main() {
//        int N;
//        scanf("%d", &N);
//        for (int i = 1; i <= N; i++)
//                count_ones(i);
//        printf("%d\n", count);
//}

int main() {
        int n, a = 1, ans = 0;
        int left, now, right;
        scanf("%d", &n);
        while (n / a) {
                left = n / (a * 10);
                now = n / a % 10;
                right = n % a;
                if (now == 0) ans += left * a;
                else if (now == 1) ans += left * a + right + 1;
                else ans += (left + 1) * a;
                a *= 10;
        }
        printf("%d\n", ans);
}
