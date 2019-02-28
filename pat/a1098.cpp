#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool equal_vecs(vector<int> &a, vector<int>&b) {
        for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i])
                        return false;
        }
        return true;
}

void read_input(int &N, vector<int> &origin, vector<int> &result) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                origin.push_back(x);
        }
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                result.push_back(x);
        }
}

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                printf("%d", v[i]);
                printf("%c", i == v.size() - 1? '\n':' ');
        }
}

int heap_sort(vector<int> &v, vector<int> &result) {
        make_heap(v.begin(), v.end());
        int flag = 0;
        int limit = 0;
        for (int i = 0; i < v.size(); i++) {
                pop_heap(v.begin(), v.end() - i);
                if (equal_vecs(v, result)) {
                        flag++;
                        limit = i + 1;
                }
                if (flag && limit == i) return 1;
        }
        return 0;
}

int insertion_sort(vector<int> &v, vector<int> &result) {
        int flag = 0;
        int limit = 0;
        for (int j = 1; j < v.size(); j++) {
                int i = j - 1;
                while (i >= 0 && v[j] < v[i]) {
                        i--;
                }  // then i + 1 is the right place
                int t = v[j];
                for (int k = j; k > i + 1; k--) {
                        v[k] = v[k - 1];
                }
                v[i + 1] = t;

                if (equal_vecs(v, result)) {
                        flag ++;
                        limit = j + 1;
                }
                if (flag && limit == j) {
                        return 0;
                }
        }
        return 1;
}

int main() {
        int N;  // 1 < N < 100, and origin can't be sorted
        vector<int> origin, result;
        read_input(N, origin, result);

        vector<int> cp_origin(origin);
        int choice = insertion_sort(cp_origin, result);
        if (choice == 0) {
                cout << "Insertion Sort" << endl;
                print_vec(cp_origin);
        } else {
                cout << "Heap Sort" << endl;
                heap_sort(origin, result);
                print_vec(origin);
        }
        return 0;
}
