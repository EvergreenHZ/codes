#include "../include/common.h"

void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
}

// reverse the array[s...e]
void reverse(int* A, int s, int e) {
        int i = s, j = e;
        for (; i < j; i++, j--) {
                swap(&A[i], &A[j]);
        }
}

int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        M = M % N;
        //printf("%d %d", N, M);
        int* A = (int*)malloc(N * sizeof(int));
        //int i = 0;
        //while (N--) {
        //        int data;
        //        scanf("%d", &data);
        //        A[i++] =  data;
        //}

        for (int i = 0; i < N; i++) {
                int data;
                scanf("%d", &data);
                A[i] =  data;
                //printf("%d ", A[i]);
        }
        //printf("\n");
        int k = N - M - 1;
        reverse(A, 0, k);
        reverse(A, k + 1, N - 1);
        reverse(A, 0, N - 1);

        for (int j = 0; j < N; j++) {
                if (j == N - 1) {
                        printf("%d\n", A[j]);
                } else {
                        printf("%d ", A[j]);
                }
        }
        return 0;
}
