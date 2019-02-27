#include "../include/common.h"

using namespace std;

void splitDigital(int n, vector<int> digitals) {
        int q = n / 10;
        int residual = n - q * 10;

        if (q == 0) {
                digitals.push_back(residual);
        } else {
                splitDigital(q, digitals);
                digitals.push_back(residual);
        }
}

void octToD(int n, int D) {
        int q = n / D;
        int residual = n - q * D;

        if (q == 0) {
                printf("%d", residual);
        } else {
                octToD(q, D);
                printf("%d", residual);
        }
}

int main()
{
        int A, B, D;
        scanf("%d %d %d", &A, &B, &D);
        octToD(A + B, D);
        printf("\n");
}
