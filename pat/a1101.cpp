#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 100010;
int left_max[MAXN] = {0};
int right_min[MAXN] = {0};
int v[MAXN] = {0};
int N;
vector<int> result;

int main() {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                int x;
                scanf("%d", &x);
                v[i] = x;
        }
        left_max[1] = v[1];
        for (int i = 2; i <= N; i++) {
                left_max[i] = max(left_max[i - 1], v[i]);
        }

        right_min[N] = v[N];
        for (int j = N - 1; j >= 1; j--) {
                right_min[j] = min(v[j], right_min[j + 1]);
        }

        for(int i = 1; i <= N; i++) {
                if (v[i] >= left_max[i] && v[i] <= right_min[i])
                        result.push_back(v[i]);
        }
        //print_mm();
        std::sort(result.begin(), result.end());

        printf("%lu\n", result.size());
        for (int i = 0; i < result.size(); i++) {
                printf("%d", result[i]);
                printf("%c", i == result.size() - 1?'\n':' ');
        }
        if (result.size() == 0)
                printf("\n");

        return 0;
}
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 100010;
int left_max[MAXN] = {0};
int right_min[MAXN] = {0};
int v[MAXN] = {0};
int N;
vector<int> result;

int main() {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                int x;
                scanf("%d", &x);
                v[i] = x;
        }
        left_max[1] = v[1];
        for (int i = 2; i <= N; i++) {
                left_max[i] = max(left_max[i - 1], v[i]);
        }

        right_min[N] = v[N];
        for (int j = N - 1; j >= 1; j--) {
                right_min[j] = min(v[j], right_min[j + 1]);
        }

        for(int i = 1; i <= N; i++) {
                if (v[i] >= left_max[i] && v[i] <= right_min[i])
                        result.push_back(v[i]);
        }
        //print_mm();
        std::sort(result.begin(), result.end());

        printf("%lu\n", result.size());
        for (int i = 0; i < result.size(); i++) {
                printf("%d", result[i]);
                printf("%c", i == result.size() - 1?'\n':' ');
        }
        if (result.size() == 0)
                printf("\n");

        return 0;
}
