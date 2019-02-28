#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

class Foo {
public:
        static const int MAXN = 320;
        static const int NOT_A_KEY = 1000000;
        int table[MAXN * MAXN];
        int block[MAXN];
        stack<int> stk;
        string message;

        Foo() {
                for (int i = 0; i < MAXN * MAXN; i++) {
                        table[i] = 0;
                }
                for (int i = 0; i < MAXN; i++) {
                        block[i] = 0;
                }
        }

        void push(int x) {
                table[x] ++;
                block[x / MAXN] ++;
                stk.push(x);
        }
        int pop() {
                if (stk.empty()) {
                        message = "Invalid";
                        return NOT_A_KEY;
                } else {
                        int x = stk.top();
                        table[x] --;
                        block[x / MAXN]--;
                        stk.pop();
                        return x;
                }
        }

        int peekMedian() {
                if (stk.empty()) {
                        message = "Invalid";
                        return NOT_A_KEY;
                } else {
                        int total_numbers = stk.size();
                        int b = total_numbers / MAXN;
                        int sum = 0;
                        int median = (total_numbers + 1) / 2;
                        int i = 0;
                        for (; i < MAXN; i++) {
                                sum += block[i];
                                if (sum >= median)
                                        break;
                        }
                        //cout << "***In Block: " << i << endl;
                        sum -= block[i];
                        int base = MAXN * i;
                        for (int j = 0; j < MAXN; j++) {
                                sum += table[j + base];
                                if (sum >= median) {
                                        //cout << base + j;
                                        return base + j;
                                }
                        }
                }
        }

        void clearMessage() {
                message = "";
        }
};

Foo foo;

int main() {
        int N;
        int key;
        string s;
        scanf("%d", &N);
        while (N--) {
                cin >> s;
                if (s == "Push") {
                        cin >> key;
                        foo.push(key);
                } else {
                        int median_key = -1;
                        if (s == "Pop") {
                                int x = foo.pop();
                                if (foo.message != "") {
                                        cout << foo.message << endl;
                                        foo.clearMessage();
                                } else {
                                        cout << x << endl;
                                }
                        } else {
                                median_key = foo.peekMedian();
                                if (foo.message == "") {
                                        cout << median_key << endl;
                                } else {
                                        cout << foo.message << endl;
                                        foo.clearMessage();
                                }
                        }
                }
        }
}
