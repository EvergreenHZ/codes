#include "../include/common.h"
#include <algorithm>
#include <utility>
using namespace std;


//// time limit exceeded
//
//int sum_dist = 0;
//
//int cal_dist(pair<int, int> &p, vector<int> &dist) {
//        int a = min(p.first, p.second);
//        int b = max(p.first, p.second);
//        int d = 0;
//        for (int i = a; i < b; i++) {
//                d += dist[i];
//        }
//        return min(d, sum_dist - d);
//}
//
//int main() {
//        int N, M;
//        vector<int> dist;
//        vector<pair<int, int> > pairs;
//
//        // N distances
//        scanf("%d", &N);
//        dist.push_back(0);
//        dist.push_back(0);
//        for (int i = 0; i < N; i++) {
//                int t;
//                scanf("%d", &t);
//                sum_dist += t;
//                dist.push_back(t);
//        }
//
//        // M pairs
//        scanf("%d", &M);
//        for (int i = 0; i < M; i++) {
//                int first, second;
//                scanf("%d %d", &first, &second);
//                pairs.push_back(pair<int, int>(first, second));
//        }
//
//        vector<int> result;
//        for (int i = 0; i < M; i++) {
//                int d = cal_dist(pairs[i], dist);
//                result.push_back(d);
//        }
//
//        for (int i = 0; i < result.size(); i++) {
//                printf("%d\n", result[i]);
//        }
//
//        return 0;
//}

int cal_dist(pair<int, int> &p, vector<int> &dist, int sum) {
        int a = min(p.first, p.second);
        int b = max(p.first, p.second);
        int dist_from_1_to_a = dist[a];
        int dist_from_1_to_b = dist[b];
        int d = dist_from_1_to_b - dist_from_1_to_a;
        return min(d, sum - d);
}
int main() {
        int N, M;
        vector<int> dist;
        dist.push_back(0);
        dist.push_back(0);  // dist from 1 to 1: 0

        scanf("%d", &N);
        int sum_dist = 0;
        for (int i = 1; i <= N; i++) {
                int t;
                scanf("%d", &t);
                sum_dist += t;
                dist.push_back(sum_dist);
        }

        vector<pair<int, int> > pairs;
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
                int a, b;
                scanf("%d", &a);
                scanf("%d", &b);
                pairs.push_back(pair<int, int>(a, b));
        }
        for (int i = 0; i < M; i++) {
                printf("%d\n", cal_dist(pairs[i], dist, sum_dist));
        }
}
