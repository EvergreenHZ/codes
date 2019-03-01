#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 100000;
map<int, vector<int> > inc_map;
int table[MAXN] = {0};

bool predict(vector<int> &v) {
        for (int i = 0; i <v.size(); i++) {
                vector<int> &incomp = inc_map[v[i]];
                for (int j = 0; j < incomp.size(); j++)
                        if (table[incomp[j]]) return false;
        }
        return true;
}

int main() {
        /* read input */
        int N, M;
        scanf("%d%d", &N, &M);
        while (N--) {
                int x, y;
                scanf("%d %d", &x, &y);
                inc_map[x].push_back(y);
                inc_map[y].push_back(x);
        }

        while (M--) {
                int n, x;
                scanf("%d", &n);
                fill(table, table + MAXN, 0);
                vector<int> t_case;
                while (n--) {
                        scanf("%d", &x);
                        t_case.push_back(x);
                        table[x] = 1;
                }
                if (predict(t_case)) cout << "Yes" << endl;
                else cout << "No" <<endl;
        }
        return 0;
}
