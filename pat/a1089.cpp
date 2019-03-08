#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> initial_seq;
vector<int> target_seq;

bool comp(const vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                if (target_seq[i] != v[i])
                        return false;
        }
        return true;
}

void print_vec(const vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
        } cout << endl;
}
bool insertion_sort(vector<int> &v) {
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

                if (comp(v)) {
                        flag ++;
                        limit = j + 1;
                }
                if (flag && limit == j) {
                        return true;
                }
        }
        return false;
}

//bool is_insert_sort(vector<int> &v) {
//        //print_vec(v);
//        bool flag = true;
//        for (int i = 1; flag && i < v.size(); i ++) {
//                if (comp(v)) {
//                        flag = false;
//                }
//                int j = i - 1;
//                for (; j >= 0; j--) {
//                        if (v[i] > v[j])
//                                break;
//                }
//                int tmp = v[i];
//                for (int k = i - 1; k >= j + 1; k--) {
//                        v[k + 1] = v[k];
//                }
//                v[j + 1] = tmp;
//        }
//        return !flag;
//}

bool is_merge_sort(vector<int> &v) {
        //print_vec(v);
        int interval = 2;
        bool flag = true;
        for (int i = 0; flag && i < v.size(); i++) {
                if (comp(v)) {
                        flag = false;
                }
                for (int j = 0; j < v.size(); j += interval) {
                        vector<int>::iterator end = min(v.end(),
                                                       v.begin() + j + interval);
                        sort(v.begin() + j, end);
                }
                //print_vec(v);
                interval *= 2;
        }
        return !flag;
}

int main() {
        int N, x;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d", &x);
                initial_seq.push_back(x);
        }
        for (int i = 0; i < N; i++) {
                scanf("%d", &x);
                target_seq.push_back(x);
        }
        vector<int> v1(initial_seq);
        vector<int> v2(initial_seq);
        if (insertion_sort(v1)) {
                printf("Insertion Sort\n");
                for (int i = 0; i < v1.size(); i++) {
                        cout << v1[i];
                        printf("%c", i == v1.size() - 1?'\n':' ');
                }
                return 0;
        }
        if (is_merge_sort(v2)) {
                printf("Merge Sort\n");
                for (int i = 0; i < v2.size(); i++) {
                        cout << v2[i];
                        printf("%c", i == v2.size() - 1?'\n':' ');
                }
                return 0;
        }
        return 0;
}
