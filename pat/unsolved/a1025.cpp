#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stu {
public:
        string id;
        int score;
        int location;
        int local_rank;
        Stu() {}
        Stu(const string &i, const int s, const int l):
                id(i), score(s), location(l) {};

        bool operator<(const Stu &s) {
                if (score != s.score) return score > s.score;
                else return id < s.id;
        }
};

void print_vec(vector<Stu> &v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i].id << " " << v[i].score << endl;
        }
}

vector<Stu> v;

int main() {
        int N_locations;
        scanf("%d", &N_locations);
        int start = 0;
        for (int i = 1; i <= N_locations; i++) {
                int K;
                scanf("%d", &K);
                for (int j = 1; j <= K; j++) {
                        string id;
                        int score;
                        cin >> id >> score;
                        v.push_back(Stu(id, score, i));
                }
                sort(v.begin() + start, v.begin() + start + K);
                for (int k = 0; k < K; k++) {
                        if (k && v[k + start].score == v[k + start - 1].score)  // same score -> same rank
                                v[k].local_rank = v[k - 1].local_rank;
                        else
                                v[k].local_rank = k + 1;
                        cout << v[k].local_rank << endl;
                }
                start += K;
        }
        cout << endl;
        cout << "*************" << endl;
        for (int i = 0; i < v.size(); i++) {
                cout << v[i].id <<" " << v[i].local_rank << endl;
        }
        sort(v.begin(), v.end());
        //for (int i = 0; i < v.size(); i++) {
        //cout << v[i].id <<" " << v[i].local_rank << endl;
        //}
        //printf("%d\n", (int)v.size());
        int rank = 1;
        for (int i = 0; i < v.size(); i++) {
                //cout << v[i].id << " ";
                //if (i && v[i].score == v[i - 1].score) {  // same score
                //        cout << rank << " ";
                //} else {
                //        rank = i + 1;
                //        cout << rank << " ";
                //}
                //cout << v[i].location << " " << v[i].local_rank << endl;
        }
        return 0;
}
