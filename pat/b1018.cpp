#include "../include/common.h"

int judge(char c1, char c2) {
        if (c1 == 'B' && c2 == 'C') return 1;
        if (c1 == 'B' && c2 == 'J') return -1;
        if (c1 == 'C' && c2 == 'J') return 1;
        if (c1 == 'C' && c2 == 'B') return -1;
        if (c1 == 'J' && c2 == 'B') return 1;
        if (c1 == 'J' && c2 == 'C') return -1;
        return 0;
}

int hash(char c) {
        switch (c) {
        case 'B': return 0;
        case 'C': return 1;
        case 'J': return 2;
        }
}

char remap(int index) {
        switch (index) {
        case 0: return 'B';
        case 1: return 'C';
        case 2: return 'J';
        }
}

int main() {
        int N;
        char c1, c2;
        scanf("%d", &N);
        int w = 0, l = 0, f = 0;
        /*
         *     B  C  J
         * w/0
         * f/1
         * l/2
         */
        int A[3][3] = { {0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0} };
        int B[3][3] = { {0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0} };

        while (N--) {
                scanf("%c %c", &c1, &c2);
                int result = judge(c1, c2);

                if (result == -1 ) {  // A lose and B win
                        A[2][hash(c1)] ++;
                        B[0][hash(c2)] ++;
                } else if (result == 0) {
                        A[1][hash(c1)] ++;
                        B[1][hash(c2)] ++;
                } else {
                        A[0][hash(c1)] ++;
                        B[2][hash(c2)] ++;
                }
        }

        int res_A[3] = {0, 0, 0};
        int res_B[3] = {0, 0, 0};

        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        res_A[i] += A[i][j];
                        res_B[i] += B[i][j];
                }
        }

        int max_A = 0, max_B = 0;
        for (int i = 1; i < 3; i++) {
                if (max_A < A[0][i]) {
                        max_A = i;
                }
                if (max_B < B[0][i]) {
                        max_B = i;
                }
        }
        char w_a = remap(max_A);
        char w_b = remap(max_B);

        for (int i = 0; i < 3; i++) {
                if (i != 2) {
                        printf("%d ", res_A[i]);
                } else {
                        printf("%d\n", res_A[i]);
                }
        }

        for (int i = 0; i < 3; i++) {
                if (i != 2) {
                        printf("%d ", res_B[i]);
                } else {
                        printf("%d\n", res_B[i]);
                }
        }
        putchar(w_a);
        putchar(' ');
        putchar(w_b);
        putchar('\n');
        return 0;
}
