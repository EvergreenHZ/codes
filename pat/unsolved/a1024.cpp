#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
long long int N, t;
int K;

void print_vec(const vector<int> &v) {
        for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
        cout << endl;
}
bool is_palindromic(const vector<int> &v) {
        int i = 0, j = v.size() - 1;
        for (; i <= j; i++, j--) {
                if (v[i] != v[j]) return false;
        }
        return true;
}

vector<int> process(const vector<int> &a, bool &flag) {
        vector<int> b(a);
        reverse(b.begin(), b.end());
        //print_vec(b);
        vector<int> result(a.size(), 0);
        for (int i = a.size() - 1; i > 0; i--) {
                int x = a[i] + b[i];
                int carry = 0;
                if (x >= 10) {
                        x = x % 10;
                        carry++;
                }
                result[i] += x;
                if (carry)
                        result[i - 1] ++;
        }
        int x = a[0] + b[0];
        if (x >= 10) {
                result[0] += x % 10;
                deque<int> q(result.begin(), result.end());
                q.push_front(1);
                result = vector<int>(q.begin(), q.end());
        } else {
                result[0] += x;
        }
        //print_vec(result);
        flag = is_palindromic(result) ? true : false;
        return result;
}

int main() {
        int count = 0;
        scanf("%lld%d", &N, &K);
        t = N;
        vector<int> a;
        do {
                a.push_back(N % 10);
                N /= 10;
        } while (N);
        if (is_palindromic(a)) {
                cout << t << endl << "0" << endl;
        }
        N = t;

        while (K--) {
                count ++;
                bool flag = false;
                vector<int> v = process(a, flag);
                a.clear();
                a = v;
                if (flag) break;
        }
        for (int i = 0; i < a.size(); i++) {
                cout << a[i];
        }
        cout << endl << count << endl;
        return 0;
}
