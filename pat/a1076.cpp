#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 1010;
int G[MAXN][MAXN] = {0};  // starting from 1
bool inq[MAXN] = {false};

int N, L;
vector<int> query;
//int level_count = 0;
//int number_forwards = 0;
int level[MAXN] = {0};

void read_input() {
        scanf("%d %d", &N, &L);
        for (int i = 1; i <= N; i++) {
                int k;
                scanf("%d", &k);
                while (k--) {
                        int x;
                        scanf("%d", &x);
                        G[x][i] = 1;  // can be reached
                }

        }
        int n;
        scanf("%d", &n);
        while (n--) {
                int x;
                scanf("%d", &x);
                query.push_back(x);
        }
}

void clear_old() {
        fill(inq, inq + N + 2, false);
        fill(level, level + N + 2, 0);
}

void bfs_a_connected_component(int u, int &number_forwards) {
        queue<int> Q;
        Q.push(u);
        inq[u] = true;
        while (!Q.empty()) {
                number_forwards ++;
                int v = Q.front();
                //cout << v << endl;
                Q.pop();
                for (int i = 1; i <= N; i++) {
                        if (G[v][i] > 0 && inq[i] == false) {
                                level[i] = level[v] + 1;
                                if (level[i] <= L) {
                                        Q.push(i);
                                        //cout << i << " is adjacent to" << v << endl;
                                        inq[i] = true;  // once enqueue, set true
                                }
                        }
                }
        }
}

int main() {
        read_input();
        for (int i = 0; i < query.size(); i++) {
                int num = -1;  // not include itself
                //cout << "***************" << endl;
                bfs_a_connected_component(query[i], num);
                clear_old();
                //cout << "***************" << endl;
                cout << num << endl;
        }
}
