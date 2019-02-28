#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

using namespace std;
unordered_map<pair<int, int>, int, pair_hash> map_inc;

bool is_compatible(int x, int y) {
        if (map_inc.find(pair<int, int>(x, y)) == map_inc.end() ||
            map_inc.find(pair<int, int>(y, x)) == map_inc.end()) {
                return true;
        } else {
                return false;
        }

}

bool predict(vector<int> &v) {
        if (v.size() <= 1) return true;
        for (int i = 0; i < v.size() - 1; i++) {
                for (int j = i + 1; j < v.size(); j++){
                        if (!is_compatible(v[i], v[j])) {
                                //cout << v[i] << " and " << v[j] << " is not compatible" << endl;
                                return false;
                        }
                        //cout << v[i] << " and " << v[j] << " is compatible" << endl;
                }
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
                pair<int, int> p(x, y);
                pair<int, int> p2(y, x);
                map_inc[p] = N;
                map_inc[p2] = N;
        }
        //cout << endl;
        //for (map<pair<int, int>, int>::iterator it = map_inc.begin(); it != map_inc.end(); it++) {
        //cout << it->first.first << "  " << it->first.second << endl;
        //}

        vector<vector<int> > test_cases;
        while (M--) {
                int n, x;
                scanf("%d", &n);
                vector<int> t_case;
                while (n--) {
                        scanf("%d", &x);
                        t_case.push_back(x);
                }
                test_cases.push_back(t_case);
        }

        /* process it */
        for (int i = 0; i < test_cases.size(); i++) {
                if (predict(test_cases[i])) {
                        cout << "Yes" << endl;
                } else {
                        cout << "No" <<endl;
                }
        }
        return 0;
}
