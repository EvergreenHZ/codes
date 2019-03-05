#include <iostream>
#include <cstdio>

using namespace std;

float m[3][3];
const char* s[3] = {"W", "T", "L"};

int find_max(int i) {
        int max_index = 0;
        for (int j = 1; j < 3; j++) {
                if (m[i][j] > m[i][max_index])
                        max_index = j;
        }
        return max_index;
}
int main() {
        for (int i = 0; i < 3; i++)
                scanf("%f%f%f", &m[i][0], &m[i][1], &m[i][2]);
        int first_game = find_max(0);
        int second_game = find_max(1);
        int third_game = find_max(2);
        //cout << first_game <<endl;
        //cout << second_game <<endl;
        //cout << third_game <<endl;

        float rewards = (m[0][first_game] * m[1][second_game] * m[2][third_game] * 0.65 - 1)  * 2;
        cout << s[first_game] << " " << s[second_game] << " " << s[third_game] << " ";
        printf("%.2f\n", rewards);
        return 0;
}
