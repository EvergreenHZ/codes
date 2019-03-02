#include <iostream>
#include <cstring>
#include <cmath> 
#include <string>
using namespace std;

char s[100];

int main() {
        //scanf("%s", s);
        //getline(stdin, s,'\n');
        fgets(s, 100, stdin);
        char *p = strchr(s, '\n');
        *p = '\0';
        //cout << s << endl;
        //exit(-1);

        int N = strlen(s);
        int n1, n2;
        for (n2 = ceil((N + 2) / 3); n2 <= N; n2++) {
                n1 = (N + 2 - n2) / 2;
                if (n1 * 2 + n2 - 2 == N && n1 <= n2) break;
        }
        cout << "n1 : n2 " << n1 << " " <<n2 << endl;
        int i, j;
        for (i = 0, j = N - 1; i < n1 - 1; i++, j--) {
                cout << s[i];
                for (int k = 0; k < n2 - 2; k++) {
                        cout << " ";
                }
                cout << s[j];
                cout << endl;
        }
        for (; i <= j; i++) {
                cout << s[i];
        }
        cout << endl;
}
