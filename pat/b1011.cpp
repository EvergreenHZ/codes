#include "../include/common.h"

int main() {
        long long A, B, C;
        int n;
        int tcase = 1;

        scanf("%d", &n);

        while (n--) {
                scanf("%lld %lld %lld", &A, &B, &C);

                const char* p = (A + B - C > 0 ? "true" : "false");
                printf("Case #%d: %s\n", tcase, p);
                tcase++;
        }
}
