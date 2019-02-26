#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class item {
public:
        int exp;
        double coef;

        item(): exp(0), coef(0.) {}
        item(int e, double c): exp(e), coef(c) {}
        item(const item& it): exp(it.exp), coef(it.coef) {}
};

void A_plus_B(vector<item> &A, vector<item> &B, vector<item> &C) {
        vector<item>::iterator ita = A.begin();
        vector<item>::iterator itb = B.begin();
        for (; ita != A.end() && itb != B.end();) {
                if ((*ita).exp == (*itb).exp) {
                        if ((*ita).coef + (*itb).coef == 0) {
                                ita++, itb++;
                                continue;
                        }
                        C.push_back(item((*ita).exp, (*ita).coef + (*itb).coef));
                        ita++, itb++;
                } else if ((*ita).exp > (*itb).exp) {
                        C.push_back(item(*ita));
                        ita++;
                } else {
                        C.push_back(item(*itb));
                        itb++;
                }
        }

        if (ita == A.end()) {
                while (itb != B.end()) {
                        C.push_back(*itb ++);
                }
        }
        if (itb == B.end()) {
                while (ita != A.end()) {
                        C.push_back(*ita++);
                }
        }
}

void read_poly(vector<item> &P) {
        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
                int exp;
                double coef;
                scanf("%d %lf", &exp, &coef);
                P.push_back(item(exp, coef));
        }
}

void print_poly(vector<item> &P) {
        int K = P.size();
        printf("%d", K);
        for (int i = 0; i < K; i++) {
                if (i == K - 1) {
                        printf(" %d %.1lf\n", P[i].exp, P[i].coef);
                } else {
                        printf(" %d %.1lf", P[i].exp, P[i].coef);
                }
        }
}

void item_times_B(item& it, vector<item> &B, vector<item> &result) {
        for (int i = 0; i < B.size(); i++) {
                int exp = it.exp + B[i].exp;
                double coef = it.coef * B[i].coef;
                result.push_back(item(exp, coef));
        }
}
void A_times_B(vector<item> &A, vector<item> &B, vector<item> &C) {
        vector<item>::iterator it = A.begin();
        for (; it != A.end(); it++) {

                vector<item> t_C = C;
                vector<item> t_result;

                item_times_B(*it, B, t_result);

                /* This is very consequential */
                C.clear();
                A_plus_B(t_result, t_C, C);
        }
}

int main() {
        vector<item> A, B, C;
        read_poly(A);
        read_poly(B);

        A_times_B(A, B, C);
        print_poly(C);

        return 0;
}
