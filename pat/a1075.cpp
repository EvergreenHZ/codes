//#include <cstdio>
//#include <vector>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 6;
//int N, K, M;
//int g_full_score[MAXN] = {0};
//
//class User{
//public:
//string id;
//int scores[MAXN];
//int perfectly_solved_probs;
//int total_score;
//bool flag;
//User() {
//for (int i = 0; i < MAXN; i++)
//scores[i] = -2;  // not submitted
//total_score = 0;
//flag = false;
//}
//User(string i, int prob_id, int score): id(i) {
//for (int i = 0; i < MAXN; i++)
//scores[i] = -2;  // not submitted
//scores[prob_id] = score;
//total_score = 0;
//flag = false;
//}
//void cal_total_score() {
//int not_compiled = 0;
//for (int i = 1; i <= K; i++) {
//if (scores[i] == g_full_score[i])
//perfectly_solved_probs++;
//if (scores[i] == -1) {
//not_compiled ++;
//continue;
//} else if (scores[i] == -2) {
//not_compiled ++;
//continue;
//}
//total_score += scores[i];
//}
//if (not_compiled == K)
//flag = true;
//}
//};
//
//bool cmp(const User& u1, const User& u2) {
//if (u1.total_score != u2.total_score)
//return u1.total_score > u2.total_score;
//else if (u1.perfectly_solved_probs != u2.perfectly_solved_probs) {
//u1.perfectly_solved_probs > u2.perfectly_solved_probs;
//} else
//return u1.id < u2.id;
//}
//
//map<string, int> m_id_to_pos;
//
//int main() {
//scanf("%d %d %d", &N, &K, &M);
//for (int i = 1; i <= K; i++)
//scanf("%d", &g_full_score[i]);
//
//vector<User> v;
//int count = 0;
//for (int i = 0; i < M; i++) {
//string id;
//int prob_id, score;
//cin >> id >> prob_id >> score;
//if (m_id_to_pos.find(id) == m_id_to_pos.end()) {  // new id
//m_id_to_pos[id] = count ++;
//v.push_back(User(id, prob_id, score));
////cout << endl << "New id: " << id <<" with socre: " << score << endl;
//} else {
//int idx = m_id_to_pos[id];
//if (score > v[idx].scores[prob_id]) {
//v[idx].scores[prob_id] = score;
//}
//}
//}
//for (int i = 0; i < count; i++)
//v[i].cal_total_score();
//sort(v.begin(), v.end(), cmp);
//
//int rank = 1;
//for (int i = 0; i < count; i++) {
//if (v[i].flag) {
//continue;
//}
//if (i && v[i].total_score == v[i - 1].total_score) {
//printf("%d %s %d ", rank, v[i].id.c_str(), v[i].total_score);
//for (int j = 1; j <= K; j++) {
//if (v[i].scores[j] == -2) {
//cout << "-";
//} else if (v[i].scores[j] == -1) {
//cout << "0";
//} else {
//cout << v[i].scores[j];
//}
//printf("%c", j == K? '\n':' ');
//}
//} else {
//rank = i + 1;
//printf("%d %s %d ", rank, v[i].id.c_str(), v[i].total_score);
//for (int j = 1; j <= K; j++) {
//if (v[i].scores[j] == -2) {
//cout << "-";
//} else if (v[i].scores[j] == -1) {
//cout << "0";
//} else {
//cout << v[i].scores[j];
//}
//printf("%c", j == K? '\n':' ');
//}
//}
//}
//return 0;
//}
//
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int maxn = 10010;
 
struct Student{
        int id;
        int score[6];
        bool flag;
        int score_all;
        int solve;
}stu[maxn];
 
int n, k, m;
int full[6];
bool cmp(Student a, Student b){
        if(a.score_all != b.score_all) return a.score_all > b.score_all;
        else if(a.solve != b.solve) return a.solve > b.solve;
        else return a.id < b.id;
} 
 
void init(){
        for(int i = 1; i <= n; i++){
                stu[i].id = i;
                stu[i].score_all = 0;
                stu[i].solve = 0;
                stu[i].flag = false;
                memset(stu[i].score, -1, sizeof(stu[i].score));
        }
}
 
int main(){
        scanf("%d%d%d", &n, &k, &m);
        init();
        for(int i = 1; i <= k; i++){
                scanf("%d", &full[i]);
        }
        int u_id, p_id, score_obtained;
        for(int i = 0; i < m; i++){
                scanf("%d%d%d", &u_id, &p_id, &score_obtained);
                if(score_obtained != -1){
                        stu[u_id].flag = true;
                }
                if(score_obtained == -1 && stu[u_id].score[p_id] == -1){
                        stu[u_id].score[p_id] = 0;
                }
                if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]){
                        stu[u_id].solve++;
                }
                if(score_obtained > stu[u_id].score[p_id]){
                        stu[u_id].score[p_id] = score_obtained;
                }
        } 
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= k; j++){
                        if(stu[i].score[j] != -1){
                                stu[i].score_all += stu[i].score[j];
                        }
                }
        }
        sort(stu + 1, stu + n + 1, cmp);
        int r = 1;
        for(int i = 1; i <= n && stu[i].flag == true; i++){
                if(i > 1 && stu[i].score_all != stu[i - 1].score_all){
                        r = i;
                }
                printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
                for(int j = 1; j <= k; j++){
                        if(stu[i].score[j] == -1){
                                printf(" -");
                        }
                        else{
                                printf(" %d", stu[i].score[j]);
                        }
                }
                printf("\n");
        }
        return 0;
}
