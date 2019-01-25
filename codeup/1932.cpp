#include "../include/common.h"

int linear_search(int *array, int num, int x) {
        for (int i = 0; i < num; i++) {
                if (array[i] == x) {
                        return i;
                }
        }
        return -1;
}

int main()
{
        int num = 0;
        int array[200];
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
                int n;
                scanf("%d", &n);
                array[i] = n;
        }
        int x;
        scanf("%d", &x);

        int index = linear_search(array, num, x);
        printf("%d\n", index);
}
