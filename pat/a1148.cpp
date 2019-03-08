#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAXN = 101;
bool identity[MAXN];
int statement[MAXN];
int N;
vector<pair<int, int> > v;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
}

// i != j
bool is_satisfied(int i, int j) {
        identity[i] = false;
        identity[j] = false;
        int count = 0;
        if ((statement[i] < 0 && identity[-statement[i]]) ||
            (statement[i] > 0 && identity[statement[i]] == false)) {  // i is lying
                if ((statement[j] < 0 && identity[-statement[j]] == false) ||
                    (statement[j] > 0 && identity[statement[j]])) {  // j is not lying
                        for (int k = 1; k <= N; k++) {  // the rest must have only one lier
                                if (k != i && k != j) {
                                        if (statement[k] < 0 && identity[-statement[k]] ||
                                            statement[k] > 0 && identity[statement[k]] == false) {  //k is lying
                                                count++;
                                                if (count >= 2) {
                                                        break;
                                                }
                                        }
                                }
                        }
                }
        }
        identity[i] = true;
        identity[j] = true;
        if (count == 1) {
                if (i > j)
                        v.push_back(pair<int, int> (j , i));
                else
                        v.push_back(pair<int, int>(i, j));
                return true;
        } else {
                return false;
        }
}

int main() {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                int x;
                scanf("%d", &x);
                statement[i] = x;
                identity[i] = true;  // suppose all are good man
        }
        // always suppose i, j are wolves, and i lied, j not
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                        if (i == j) continue;
                        else {
                                is_satisfied(i, j);
                        }
                }
        }
        sort(v.begin(), v.end());
        if (v.size() == 0) {
                printf("No Solution\n");
        } else {
                printf("%d %d\n", v[0].first, v[0].second);
        }
}
