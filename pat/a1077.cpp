#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
        vector<string> v;
        int N;
        scanf("%d", &N);
        getchar();  // '\n'
        char s[270];
        int min = 500;
        while (N--) {
                // read string and truncate '\n'
                char *q = fgets(s, 270, stdin);
                char *p = strchr(s, '\n');
                if (p)
                        *p = '\0';

                int len = strlen(s);
                if (min > len)
                        min = len;
                reverse(s, s + len);
                v.push_back(string(s));

                fill(s, s + 270, '\0');
        }
        int i = 0;
        for (; i < min; i++) {
                bool flag = false;
                for (int j = 1; j < v.size(); j++) {
                        if (v[0][i] != v[j][i]) {
                                flag = true;
                                break;
                        }
                }
                if (flag) break;
        }
        if (i == 0) cout << "nai" << endl;
        else {
                for (int k = i - 1; k >= 0; k--) {
                        printf("%c", v[0][k]);
                }
                cout << endl;
        }
        return 0;
}
