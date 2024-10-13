#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int* a, int* b) {
    int tmp = (*a);
    *a = *b;
    *b = tmp;
}
void func_1(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[j], &a[i]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int * a = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    func_1(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
     */
}
