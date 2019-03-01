#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;
int dp[MAXN] = {0};
int G[MAXN][MAXN] = {0};
int choice[MAXN] = {0};

int dp_dag_longest_path(int i) {
        if (dp[i] != 0) return dp[i];
        else {
                for (int j = 0; j < MAXN; j++) {
                        if (G[i][j] > 0) {  // adjacent
                                dp[i] = max(dp[i], dp[j] + G[i][j]);
                        }
                }
        }
}
