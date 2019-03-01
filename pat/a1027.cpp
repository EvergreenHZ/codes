#include <iostream>
#include <cstdio>

using namespace std;
char colors[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void print_out(int x) {
        int a[4];
        int count = 0;
        do {
                a[count++] = x % 13;
                x /= 13;
        } while (x);
        if (count == 1) {
                printf("0%c", colors[a[0]]);
        } else {
                printf("%c%c", colors[a[1]], colors[a[0]]);
        }
}

int main() {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        cout << "#";
        print_out(x);
        print_out(y);
        print_out(z);
        cout << endl;
}
