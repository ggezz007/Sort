#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void func_1(int* a, int n) {
    int ch = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <n-1; i++) {
            if (a[i] > a[i+1]) {
                ch = a[i+1];
                a[i+1] = a[i];
                a[i] = ch;
            }
        }
    }
    return;
}
int main() {
    int n;
    scanf("%d", &n);
    int * a = (int*) malloc(n*sizeof(int));
    for (int j = 0; j < n; j++) {
        scanf("%d", &a[j]);
    }
    func_1(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
    */
}
