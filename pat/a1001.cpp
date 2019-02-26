#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i];
        }
        cout << endl;
}

void split(int c, vector<int> &v) {
        /* keep c always not negative */
        c = c > 0 ? c  : -c;
        while (c != 0) {
                v.push_back(c % 10);
                c = c / 10;
        }

        if (v.size() <= 3){
                reverse(v.begin(), v.end());
                return;
        }

        vector<int> tmp;
        for (int i = 1; i <= v.size(); i++) {
                tmp.push_back(v[i - 1]);
                if (i % 3 == 0) {
                        tmp.push_back(-1);
                }
        }
        reverse(tmp.begin(), tmp.end());
        v = tmp;
}

void format(int c) {
        vector<int> v;
        split(c, v);
        for (int i = 0; i < v.size(); i++) {
                if (i == 0 && v[i] == -1) {
                        continue ;
                }
                if (v[i] == -1) {
                        cout << ",";
                } else {
                        cout << v[i];
                }
        }
}

int main() {
        /* input */
        int a, b;
        scanf("%d %d", &a, &b);
        /* sum */
        int c = a + b;

        if (c == 0) {
                cout << 0 << endl;
                return 0;
        }

        /* output */
        bool flag = (c < 0 ? true : false);

        if (flag) {
                printf("-");
        }
        format(c);
        cout << endl;

        return 0;
} 
