#include "../include/common.h"

void spilit_digitals(long long x, int* digitals) {
        if (x == 0) {
                digitals[0] ++;
        } else {
                digitals[x % 10] ++;
                x /= 10;
                spilit_digitals(x, digitals);
        }
}

long long construct_PA(int* digitals, int D_A) {
        int total = digitals[D_A];
        long long sum = 0;
        long long base = 1;

        while (total--) {
                sum += base * D_A;
                base *= 10;
        }

        return sum;
}

//void test() {
//        long long x = 3862767;
//        int digitals[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//        spilit_digitals(x, digitals);
//        long long PA = construct_PA(digitals, 6);
//
//        printf("%lld\n", PA);
//}

int main()
{
        long long A, B;
        int D_A, D_B;
        scanf("%lld %d %lld %d", &A, &D_A, &B, &D_B);
        int digitals_A[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int digitals_B[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        spilit_digitals(A, digitals_A);
        spilit_digitals(B, digitals_B);

        long long PA, PB;
        PA = construct_PA(digitals_A, D_A);
        PB = construct_PA(digitals_B, D_B);

        printf("%lld\n", PA + PB);
        return 0;
}
