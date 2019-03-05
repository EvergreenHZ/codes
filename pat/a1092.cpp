#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int hash_table[128] = {0};

bool check(string s) {
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
                if (--hash_table[s[i]] < 0)
                        flag = false;
        }
        return flag;
}

int main() {
        string sample_string, target_string;
        cin >> sample_string >> target_string;
        for (int i = 0; i < sample_string.size(); i++) {
                hash_table[sample_string[i]] ++;
        }

        bool flag = check(target_string);
        if (flag) {
                int extra = 0;
                for (int i = 0; i < 128; i++) {
                        extra += hash_table[i];
                }
                cout << "Yes " << extra << endl;
        } else {
                int missing = 0;
                for (int i = 0; i < 128; i++) {
                        if (hash_table[i] < 0) {
                                missing += hash_table[i];
                        }
                }
                cout << "No " << -missing << endl;
        }
}
