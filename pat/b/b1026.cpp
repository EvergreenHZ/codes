#include "../include/common.h"

const int CLK_TLK_ = 100;

void format_log(int x) {
        if (x > 10) {
                printf("%d", x);
        } else {
                printf("0%d", x);
        }
}

void divide_over(int *diff, double base) {
        double q = (*diff) / base;
        int int_q = (int)q;

        if (q >= (int_q + 0.5)) {
                *diff = int_q + 1;
        } else {
                *diff = int_q;
        }

}

int main() {
        int C1, C2;
        scanf("%d %d", &C1, &C2);
        int diff = C2 - C1;
        //printf("%d\n", diff);
        int hh = 0, mm = 0, ss = 0;

        divide_over(&diff, CLK_TLK_);

        ss = diff % 60;
        diff /= 60;
        mm = diff % 60;
        diff /= 60;
        hh = diff;

        // output
        format_log(hh);
        putchar(':');
        format_log(mm);
        putchar(':');
        format_log(ss);
        printf("\n");

        return 0;
}
