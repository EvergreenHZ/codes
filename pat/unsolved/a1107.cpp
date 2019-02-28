#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
vector<vector<int> > persons;

void init_father(int* father, const int &N) {
        for (int i = 0; i < N; i++) {
                father[i] = i;
        }
}

// check if two persons have same hobbies
bool have_same_hobbies(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        for (; i < a.size(); i++) {
                for (; j < b.size(); j++) {
                        if (a[i] == b[j]) {  // have same hobby
                                return true;
                        }
                }
        }
        return false;
}

int find_root(int *father, int i) {
        if (father[i] == i) {
                return i;
        } else {  // path compression
                return father[i] = find_root(father, father[i]);
        }
}

void Union(int* father, int N) {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        int root_i = find_root(father, i);
                        int root_j = find_root(father, j);
                        if (root_i != root_j) {  // not in the same set
                                if (have_same_hobbies(persons[i], persons[j])) {
                                        father[root_i] = root_j;
                                }
                        }
                }
        }
}

void print_father(int* father, int N) {
        for (int i = 0; i < N; i++) {
                cout << father[i] << " ";
        }
        cout << endl;
}

int main() {
        int N;
        scanf("%d", &N);
        int x = N;
        int *father = new int[N];
        init_father(father, N);  // init the array
        while (N--) {
                vector<int> hobbies;
                int k;
                int x;
                scanf("%d:", &k);
                while (k--) {
                        scanf("%d", &x);
                        hobbies.push_back(x);
                }
                persons.push_back(hobbies);
        }
        N = x;  // recover N
        Union(father, N);

        // find the root and count
        int *flag = new int[N];
        for (int i = 0; i < N; i++) {
                flag[i] = 0;
        }
        for (int i = 0; i < N; i++) {
                int root_i = find_root(father, i);
                flag[root_i] ++;
        }
        vector<int> v;
        for (int i = 0; i < N; i++) {
                if (flag[i] != 0) {
                        v.push_back(flag[i]);
                }
        }
        cout << v.size() << endl;
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0; i--) {
                cout << v[i];
                printf("%c", i == 0? '\n':' ');
        }
}
