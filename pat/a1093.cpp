
#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;
int leftNumP[MAXN] = {0};
char c[MAXN];

int main() {
        fgets(c, MAXN, stdin);
        char *p = strchr(c, '\n');
        *p = '\0';
        int len = strlen(c);
        for (int i = 0; i < len; i++) {
                if (i != 0) leftNumP[i] = leftNumP[i - 1];
                if (c[i] == 'P') leftNumP[i] ++;
        }
        int rightNumT = 0;
        int ans = 0;
        for (int i = len - 1; i >=0 ;i--) {
                if (c[i] == 'T') {
                        rightNumT ++;
                }
                if (c[i] == 'A') {
                        ans = (ans + leftNumP[i] * rightNumT) % MOD;
                }
        }
        printf("%d\n", ans);
}
