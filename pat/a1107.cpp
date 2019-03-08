#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <map>

using namespace std;
const int MAXN = 1010;
vector<vector<int> > persons;
int father[MAXN] = {0};
int N;
map<int, int> m_root_members;

void init_uf() {
        for (int i = 0; i <= N; i++) {
                father[i] = i;
        }
}

int find_root(int i) {
        if (father[i] == i) return i;
        else
                return father[i] = find_root(father[i]);
}

void Union(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        if (root_i != root_j)
                father[root_i] = root_j;
}

bool have_same_hobby(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < v1.size(); i++) {
                for (int j = 0; j < v2.size(); j++) {
                        if (v1[i] == v2[j])
                                return true;
                }
        }
        return false;
}

int main() {
        scanf("%d", &N);
        init_uf();
        for (int i = 0; i < N; i++) {
                int k;
                vector<int> hobbies;
                scanf("%d: ", &k);
                for (int j = 0; j < k; j++) {
                        int x;
                        scanf("%d", &x);
                        hobbies.push_back(x);
                }
                persons.push_back(hobbies);
        }

        for (int i = 1; i <= N; i++) {
                for (int j = 1; j<= N; j++) {
                        if (have_same_hobby(persons[i - 1], persons[j - 1])) {
                                //cout << i << " and " << j << " has same hobby" << endl;
                                //for (int k = 0; k < persons[i - 1].size(); k++)
                                //        cout << persons[i - 1][k] << " ";
                                //cout << endl;
                                //for (int k = 0; k < persons[j - 1].size(); k++)
                                //        cout << persons[j - 1][k] << " ";
                                //cout << endl;
                                Union(i, j);
                        }
                }
        }
        //for (int i = 1; i <= N; i++) {
        //find_root(i);
        //}
        //for (int i = 1; i <= N; i++) {
        //        cout << father[i] << " ";
        //}  cout << endl;
        for (int i = 1; i <= N; i++) {
                m_root_members[find_root(i)] ++;
        }
        cout << m_root_members.size() << endl;
        vector<int> v;
        map<int, int>::iterator it = m_root_members.begin();
        while (it != m_root_members.end()) {
                v.push_back(it->second);
                it++;
        }
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0; i--) {
                printf("%d", v[i]);
                printf("%c", i == 0 ? '\n':' ');
        }
        return 0;
}
