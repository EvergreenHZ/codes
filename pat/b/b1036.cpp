#include "../include/common.h"

int main()
{
        int N;
        char c;
        scanf("%d %c", &N, &c);

        int cols = N / 2;
        if (N % 2 == 1) {
                cols++;
        }
        for (int i = 1; i <= cols; i++) {
                if (i == 1 || i == cols) {
                        for (int j = 1; j <= N; j++) {
                                putchar(c);
                        }
                        printf("\n");
                } else {
                        for (int j = 1; j <= N; j++) {
                                if (j == 1 || j == N) {
                                        putchar(c);
                                } else {
                                        putchar(' ');
                                }
                        }
                        printf("\n");
                }
        }
}
