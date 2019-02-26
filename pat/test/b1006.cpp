#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
        int N;
        scanf("%d", &N);

        vector<int> v;
        do {
                v.push_back(N % 10);
                N /= 10;
        } while (N);

        if (N >= 100) {
                for (int i = 0; i < v[0]; i++) {
                        cout << 'B';
                }
                for (int i = 0; i < v[1]; i++) {
                        cout << 'S';
                }
                for (int i = 1; i <= v[2]; i++) {
                        cout <<i;
                }
                cout << endl;
                return 0;
        }
        if (N >= 10) {
                for (int i = 0; i < v[1]; i++) {
                        cout << 'S';
                }
                for (int i = 1; i <= v[2]; i++) {
                        cout <<i;
                }
                cout << endl;
                return 0;
        }
        for (int i = 1; i <= v[2]; i++) {
                cout <<i;
        }
        cout << endl;
        return 0;
}
