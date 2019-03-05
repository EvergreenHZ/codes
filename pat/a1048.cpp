#include <cstdio>

const int MAXN = 510;
int coins[MAXN] = {0};

int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                coins[x] ++;
        }
        if (M > 1000) {
                printf("No Solution\n");
                return 0;
        }
        int V1, V2;
        for (int i = 1; i <= 500; i++) {
                if (coins[i]) {
                        V1 = i;
                        coins[i] --;
                        V2 = M - V1;
                        if (V2 > 500) {
                                continue;
                        }
                        if (coins[V2]) {
                                printf("%d %d\n", V1, V2);
                                return 0;
                        }
                }
        }
        printf("No Solution\n");
        return 0;
}
