
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 100;
int father[MAXN] = {0};
bool isRoot[MAXN] = {false};
map<int, int> info_sets;  // root->members

void init_sets() {
        for (int i = 0; i < MAXN; i++) {
                father[i] = i;
                isRoot[i] = false;
        }
}

int find_root(int i) {
        if (i == father[i]) {
                return i;
        } else {
                return father[i] = find_root(father[i]);
        }
}

int Union(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);

        if (root_i == root_j) {
                return root_i;
        } else {
                father[root_i] = root_j;
        }
}

int get_number_of_sets() {
        for (int i = 0; i < MAXN; i++) {
                if (find_root(i) == i) {
                        isRoot[i] = true;
                }
        }

        int count = 0;
        for (int i = 0; i < MAXN; i++) {
                if (isRoot[i])
                        count ++;
        }
}

void get_members_of_sets() {
        for (int i = 0; i < MAXN; i++) {
                if (isRoot[i])
                        info_sets[i] = 0;
        }
        for (int i = 0; i < MAXN; i++) {
                info_sets[find_root(i)] ++;
        }
}


int main() {
        return 0;
}
