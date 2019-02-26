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

bool have_same_hobbies(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        for (; i < a.size(); i++) {
                for (; j < b.size(); j++) {
                        if (a[i] == b[j]) {
                                return true;
                        }
                }
        }
        return false;
}

int find_root(int *father, int i) {
        if (father[i] == i) {
                return i;
        } else {
                return father[i] = find_root(father, father[i]);
        }
}

void Union(int* father, int N) {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        int root_i = find_root(father, i);
                        int root_j = find_root(father, j);
                        if (root_i == root_j) {  // in same set
                                continue;
                        } else {  // not in same set, do union
                                if (have_same_hobbies(persons[i], persons[j])) {
                                        father[i] = root_j;
                                }
                        }
                }
        }
}

void print_persons() {
        for (int i = 0; i < persons.size(); i++) {
                for (int j = 0; j < persons[i].size(); j++) {
                        cout << persons[i][j];
                }
                cout << endl;
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
        init_father(father, N);
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
        N = x;
        Union(father, N);

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
                if (i == 0) {
                        cout << endl;
                } else {
                        cout << " ";
                }
        }
}
