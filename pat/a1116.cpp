#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 10010;
int is_checked[MAXN] = {false};
map<string, int> m_id_to_rank;
bool is_prime_flag[MAXN] = {false};

bool is_prime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i <= ceil(sqrt(x)); i++) {
                if (x % i == 0) return false;
        }
        return true;
}


int main() {
        int N, K;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
                string id;
                cin >> id;
                m_id_to_rank[id] = i;
                if (is_prime(i))
                        is_prime_flag[i] = true;
        }
        scanf("%d", &K);
        while (K--) {
                string id;
                cin >> id;
                cout << id <<": ";
                if (m_id_to_rank.find(id) == m_id_to_rank.end()) {
                        printf("Are you kidding?\n");
                } else {
                        int rank = m_id_to_rank[id];
                        if (is_checked[rank]) {
                                printf("Checked\n");
                        } else {
                                if (rank == 1) {
                                        cout << "Mystery Award"<<endl;
                                } else if (is_prime_flag[rank]) {
                                        cout << "Minion" << endl;
                                } else {
                                        cout << "Chocolate" << endl;
                                }
                                is_checked[rank] = true;
                        }
                }

        }
        return 0;
}
