#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MAXN = 2010;
map<string, int> nameToNum;  // name->node_num
map<int, string> numToName;  // node_num->name
map<string, int> gang;  // head->num
bool vis[MAXN] = {false};
int G[MAXN][MAXN] = {0};
int numPerson = 0;
int weights[MAXN] = {0};
int K;

int change(string& name) {
        if (nameToNum.find(name) != nameToNum.end()) {  // name already exits
                return nameToNum[name];
        } else {  // name not exits
                nameToNum[name] = numPerson;
                numToName[numPerson] = name;
                return numPerson++;  // number of persons increase
        }
}

void DFS(int start_node, int &head, int &numMember, int &totalVal) {
        numMember++;  // 'Cause start_node must be one of the gang
        vis[start_node] = true;  // now this one is visited
        // because you need to find the head of the gang, check point weights
        if (weights[head] < weights[start_node]) {
                head = start_node;
                //cout << "head is " << head << endl;
        }

        // do DFS
        for (int i = 0; i < numPerson; i++) {
                if (G[start_node][i] > 0) {  // if i is adjacent
                        totalVal += G[start_node][i];
                        // avoid adding same loop edge for two times when backtrace
                        G[start_node][i] = G[i][start_node] = 0;
                        if (vis[i] == false) {
                                DFS(i, head, numMember, totalVal);
                        }
                }
        }
}

void DFSTraversal() {
        for (int i = 0; i < numPerson; i++) {
                if (vis[i] == false) {  // if not visited, visit this component
                        int head = i, numMember = 0, totalVal = 0;
                        DFS(i, head, numMember, totalVal);
                        if (numMember > 2 && totalVal > K)
                                gang[numToName[head]] = numMember;
                }
        }
}

int main() {
        int N;
        //scanf("%d %d", &N, &K);
        cin >> N >> K;
        string name1, name2;
        int time_length;
        for (int i = 0; i < N; i++) {
                cin >> name1 >> name2 >> time_length;
                int id1 = change(name1);
                int id2 = change(name2);
                weights[id1] += time_length;
                weights[id2] += time_length;
                G[id1][id2] += time_length;
                G[id2][id1] += time_length;

        }
        //cout << numPerson << endl;
        //cout << nameToNum.size() << " " << numToName.size() << endl;
        // for (int i = 0; i < numPerson; i++) {
        //         for (int j = 0; j < numPerson; j++) {
        //                 cout << G[i][j] << " ";
        //         }
        //         cout << endl;
        // }

        DFSTraversal();
        cout << gang.size() << endl;
        map<string, int>::iterator it;
        for (it = gang.begin(); it != gang.end(); it ++) {
                cout << it->first << " " << it->second << endl;
        }
        return 0;
}
