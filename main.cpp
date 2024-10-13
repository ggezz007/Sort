#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



const long long maxn = 100000;
const long long INF = 1e9;
const long long p = 101;
const long long mod = 1e9 + 7;
const int inf = 1200000000;
int qsort_1_stage(int* a, int left, int right) {
    int mid = a[(left+right)/2];
    int l = left-1;
    int r = right+1;
    while(true) {
        l+=1;
        while (a[l] < mid) {
            l+=1;
        }
        r-=1;
        while (a[r] > mid) {
            r-=1;
        }
        if (l >= r) {
            return r;
        }
        int per;
        per = a[l];
        a[l] = a[r];
        a[r] = per;
    }
}
void qsort_2_stage(int* a, int left, int right) {
    if (left < right) {
        int razd = qsort_1_stage(a, left, right);
        qsort_2_stage(a, left, razd);
        qsort_2_stage(a, razd+1, right);
    }
}
signed main() {
    int n;
    scanf("%d", &n);
    int * arr = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort_2_stage(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
    */
}