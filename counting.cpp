#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int * a = (int*) malloc(n*sizeof(int));
    int * b = (int*) calloc(100000, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] += 1;
    }
    for (int i = 0; i < 100000; i++) {
        if (b[i]!=0) {
            for (int j = 0; j < b[i]; j++) {
                printf("%d ", i);
            }
        }
    }
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
    */
}
