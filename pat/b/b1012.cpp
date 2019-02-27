#include "../include/common.h"
#include <cstdio>
#include <cstdlib>

int main() {
        int N;
        scanf("%d", &N);
        int *A = (int*)malloc(sizeof(int) * N);

        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                A[i] = x;
        }

        int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
        int count[6] = {0,0,0,0,0,0};
        bool flag = true;
        for (int i = 0; i < N; i ++) {
                int residual = A[i] % 5;

                switch (residual) {
                case 0: if (((A[i] >> 1) << 1) == A[i]) {
                                count[1] ++;
                                A1 += A[i];
                        }
                        break;
                case 1: if (flag) {
                                A2 += A[i];
                                count[2] ++;
                                flag = false;
                        } else {
                                A2 -= A[i];
                                count[2] ++;
                                flag = true;
                        }
                        break;
                case 2: A3++;
                        count[3] ++;
                        break;
                case 3: A4 += A[i];
                        count[4] ++;
                        break;
                case 4: if (A5 < A[i]) {
                                count[5] ++;
                                A5 = A[i];
                        }
                }

        }
        if (count[1] == 0) {
                printf("N ");
        } else {
                printf("%d ", A1);
        }

        if (count[2] == 0) {
                printf("N ");
        } else {
                printf("%d ", A2);
        }

        if (count[3] == 0) {
                printf("N ");
        } else {
                printf("%d ", count[3]);
        }

        if (count[4] == 0) {
               printf("N ");
        } else {
                printf("%.1f ", A4 / (double)count[4]);
        }

        if (count[5] == 0) {
                printf("N\n");
        } else {
                printf("%d\n", A5);
        }
        return 0;
}

