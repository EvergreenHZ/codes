#include <iostream>
#include <cstdio>
#include <vector>

int digit[10] = {0};

bool is_palindromic(int len) {
        int i = 0, j = len - 1;
        for (; i <= j; i++, j--) {
                if (digit[i] != digit[j]) return false;
        }
        return true;
}

void print_d(int len) {
        for (int i = len - 1; i >= 0; i --) {
                printf("%d", digit[i]);
                printf("%c", i == 0 ? '\n':' ');
        }
}

int main() {
        int N, base;
        scanf("%d%d", &N, &base);
        int count = 0;
        do {
                digit[count++] = N % base;
                N /= base;
        } while (N);
        printf("%s\n", is_palindromic(count)?"Yes":"No");
        print_d(count);
        return 0;
}
