#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
        int N, p;
        scanf("%d %d", &N, &p);
        vector<int> v;
        for (int i = 0; i < N; i ++) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
        }
        sort(v.begin(), v.end());
        int len = 0;
        for (int i = 0; i < v.size(); i++) {
                int j = upper_bound(v.begin() + i, v.end(), (long long)v[i] * p) - v.begin();
                len = max(len, j - i);
        }
        printf("%d\n", len);
        return 0;
}

//#include <vector>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//        int N, p;
//        scanf("%d %d", &N, &p);
//        vector<int> v;
//        for (int i = 0; i < N; i ++) {
//                int x;
//                scanf("%d", &x);
//                v.push_back(x);
//        }
//        sort(v.begin(), v.end());
//        int len = 0;
//        for (int i = 0; i < v.size() - len; i++) {
//                for (int j = v.size() - 1; j >= i; j--) {
//                        if (v[j] <= v[i] * p) {
//                                if (len < j - i + 1) {
//                                        len = j - i + 1;
//                                }
//                        }
//                }
//        }
//        printf("%d\n", len);
//        return 0;
//}
