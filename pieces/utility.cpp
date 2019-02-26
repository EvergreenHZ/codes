#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void split(int x, vector<int> &v) {
        x = x < 0 ? -x : x;
        while (x != 0) {
                v.push_back(x % 10);
                x /= 10;
        }
        reverse(v.begin(), v.end());
}

/* double pointers technique*/
void xtp_reverse(int *a, int n) {
        int i = 0, j = n - 1;
        for (; i < j; i++, j--) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
        }
}

void xtp_swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
}

/* ascii code 0-9, A-Z, a-z */
/* map, set */
/* bs */
/* lower_bound, upper_bound */

/*
 * Have to handle == case
 */
class Obj {
public:
        int first_key;
        int second_key;
        int third_key;

        /* 
         * increasing key order 
         * overload < function, then you can use sort.
         */
        bool operator<(const Obj &o) {
                if (first_key != o.first_key) 
                        return first_key < o.first_key;
                if (second_key != o.second_key)
                        return second_key < o.second_key;
                if (third_key != o.third_key)
                        return third_key < o.third_key;
        }
};
