#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1010;
bool G[MAXN][MAXN] = {false};
int N, M, K;

void init(int* father, int N) {
        for (int i = 1; i <= N; i++)
                father[i] = i;
}

int find_root(int * father, int i) {
        if (father[i] == i) return i;
        else return father[i] = find_root(father, father[i]);
}

void Union(int* father, int i, int j) {
        int root_i = find_root(father, i);
        int root_j = find_root(father, j);
        if (root_i != root_j)
                father[root_i] = root_j;
}

int main() {
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                G[u][v] = true;
                G[v][u] = true;
        }
        int *father = new int[N + 1];
        for (int i = 0; i < K; i++) {
                int x;
                scanf("%d", &x);
                init(father, N);
                for (int j = 1; j <= N; j++) {
                        for (int k = 1; k <= N; k++) {
                                if (G[j][k] && j != x && k != x)
                                        Union(father, j, k);
                        }
                }
                int connected_components = 0;
                for (int j = 1; j <= N; j++) {
                        if (father[j] == j)
                                connected_components++;
                }
                cout << connected_components - 2 << endl;
        }
}
