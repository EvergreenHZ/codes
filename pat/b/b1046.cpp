#include "../include/common.h"

int main() {
        int num_in;
        int A_bawl, A_fec, B_bawl, B_fec;
        int cups_A = 0, cups_B = 0;

        scanf("%d", &num_in);
        while (num_in--) {
                scanf("%d %d %d %d", &A_bawl, &A_fec, &B_bawl, &B_fec);
                int sum = A_bawl + B_bawl;

                if (A_fec == sum && B_fec != sum) {
                        cups_B ++;
                } else if (A_fec != sum && B_fec == sum) {
                        cups_A ++;
                } else {
                        continue;
                }
        }

        printf("%d %d\n", cups_A, cups_B);
}
