#include "../include/common.h"
#include <algorithm>
using namespace std;

bool is_A_plus_B_bigger_than_C(string A, string B, string C) {
        long double a = stold(A);
        long double b = stold(B);
        long double c = stold(C);

        if (a + b > c) {
                return true;
        } else {
                return false;
        }
}

int main() {
        char a[64], b[64], c[64];
        bool result[11];
        fill(result, result + 10, 0);
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                scanf("%s %s %s", a, b, c);
                result[i] = is_A_plus_B_bigger_than_C(a, b, c);
        }
        for (int i = 1; i <= N; i++) {
                cout << "Case #" << i << ": " << (result[i] ? "true" : "false") << endl;
        }
        return 0;
}
