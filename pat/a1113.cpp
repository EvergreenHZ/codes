#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
        }
        sort(v.begin(), v.end());
        int delta_n = 0;
        int delta_s = 0;
        int sum_l = 0, sum_r = 0;
        if (N % 2 != 0) {
                delta_n = 1;
        }
        for (int i = 0; i < N / 2; i++) {
                sum_l += v[i];
        }
        for (int i = N / 2; i < N; i++) {
                sum_r += v[i];
        }
        delta_s = sum_r - sum_l;
        printf("%d %d\n", delta_n, delta_s);
        return 0;
}
