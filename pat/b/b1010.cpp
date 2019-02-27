#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class item {
public:
        int coef;
        int exp;

        item(): coef(0), exp(0) {}
        item(int c, int e): coef(c), exp(e) {}
};

void derivative(vector<item> &poly, vector<item> &result) {
        for (int i = 0; i < poly.size(); i++) {
                int c;
                int e;
                if (poly[i].coef == 0 || poly[i].exp == 0) {
                        c = 0;
                        e = 0;
                } else {
                        c = poly[i].coef * poly[i].exp;
                        e = poly[i].exp - 1;
                        result.push_back(item(c, e));
                }
        }
}

void print_vec(vector<item> &v) {
        int i = 0;
        int count = 0;
        for (i = 0; i < v.size(); i++) {
                if (i == v.size() - 1) {
                        if (v[i].coef == 0) {
                                continue;
                        }
                        printf("%d %d\n", v[i].coef, v[i].exp);
                        count ++;
                } else {
                        printf("%d %d ", v[i].coef, v[i].exp);
                        count ++;
                }
        }
        if (count == 0) {
                printf("0 0\n");
        }
        return ;
}


int main() {
        vector<item> polynomial;
        int coef;
        int exp;
        while (scanf("%d %d", &coef, &exp) != EOF) {
                polynomial.push_back(item(coef, exp));
        }

        vector<item> result;
        derivative(polynomial, result);
        print_vec(result);
        return 0;
}
