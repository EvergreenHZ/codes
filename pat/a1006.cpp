#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Stu {
public:
        char id[20];
        int in_hh, in_mm, in_ss;
        int out_hh, out_mm, out_ss;


};

int time_to_int(Stu &x, int flag) {
        int h, m, s;
        if (flag) {  // sign time
                h = x.in_hh;
                m = x.in_mm;
                s = x.in_ss;
        } else {
                h = x.out_hh;
                m = x.out_mm;
                s = x.out_ss;
        }
        return h * 3600 + m * 60 + s;
}

int main() {
        int N;
        scanf("%d", &N);
        Stu A, B, t;
        scanf("%s %d:%d:%d", t.id, &t.in_hh, &t.in_mm, &t.in_ss);
        scanf("%d:%d:%d", &t.out_hh, &t.out_mm, &t.out_ss);

        A = t;
        B = t;
        while (-- N) {
                scanf("%s %d:%d:%d", t.id, &t.in_hh, &t.in_mm, &t.in_ss);
                scanf("%d:%d:%d", &t.out_hh, &t.out_mm, &t.out_ss);

                int t_in_time = time_to_int(t, 1);
                int A_in_time = time_to_int(A, 1);
                if (t_in_time < A_in_time) {
                        A = t;
                }

                int t_out_time = time_to_int(t, 0);
                int B_out_time = time_to_int(B, 0);
                if (t_out_time > B_out_time) {
                        B = t;
                }
        }

        printf("%s %s\n", A.id, B.id);
        return 0;
}
