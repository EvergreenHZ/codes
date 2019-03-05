#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool hash_table[128] = {false};
char line[10010];
char result[10010];

int main() {
        fgets(line, 10010, stdin);
        char c;
        while (true) {
                c = getchar();
                if (c == '\n') {
                        break;
                } else {
                        hash_table[c] = true;
                }
        }
        int j = 0;
        for (int i = 0; line[i] != '\0'; i++) {
                if (!hash_table[line[i]])
                        result[j++] = line[i];
        }
        cout << result;
        return 0;
}
