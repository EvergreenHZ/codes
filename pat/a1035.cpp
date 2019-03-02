#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
class Account {
public:
        char name[20];
        char passwd[20];
        char modified_passwd[20];
        bool modified;
        Account():modified(false) {}
};

vector<Account> origin_vec;
vector<Account*> modified_vec;

int main() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                Account* p = new Account();
                scanf("%s %s", p->name, p->passwd);
                int j = 0;
                for (;p->passwd[j] != '\0'; j++) {
                        if (p->passwd[j] == '1') {
                                p->modified_passwd[j] = '@';
                                p->modified = true;
                                continue;
                        }
                        if (p->passwd[j] == '0') {
                                p->modified_passwd[j] = '%';
                                p->modified = true;
                                continue;
                        }
                        if (p->passwd[j] == 'l') {
                                p->modified_passwd[j] = 'L';
                                p->modified = true;
                                continue;
                        }
                        if (p->passwd[j] == 'O') {
                                p->modified_passwd[j] = 'o';
                                p->modified = true;
                                continue;
                        }
                        p->modified_passwd[j] = p->passwd[j];
                }
                p->modified_passwd[j] = '\0';
                if (p->modified) modified_vec.push_back(p);
        }
        if (modified_vec.size() != 0) {
                cout << modified_vec.size() << endl;
                for (int i = 0; i < modified_vec.size(); i++) {
                        cout << modified_vec[i]->name << " " << modified_vec[i]->modified_passwd << endl;
                }
        } else {
                if (N == 1) cout << "There is 1 account and no account is modified" << endl;
                else
                        cout << "There are " << N << " accounts and no account is modified" << endl;
        }
}
