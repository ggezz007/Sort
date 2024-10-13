#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const long long maxn = 100000;
const long long INF = 1e9;
const long long p = 101;
const long long mod = 1e9 + 7;
const long long inf = 1e9;

void mergesort(int * a, int sz) {
    if (sz == 1) {
        return;
    }
    int leftsz = sz/2, rightsz = sz-sz/2;
    int * a_left = (int*)malloc(leftsz*sizeof(int));
    int * a_right = (int*)malloc(rightsz*sizeof(int));

    for (int i = 0; i < leftsz; i++) {
        a_left[i] = a[i];
    }
    for (int j = 0; j < rightsz; j++) {
        a_right[j] = a[j+sz/2];
    }
    mergesort(a_left, leftsz);
    mergesort(a_right, rightsz);
    int ls = 0, rs = 0, t = 0;
    while (ls < leftsz && rs < rightsz) {
        if (a_left[ls] < a_right[rs]) {
            a[t] = a_left[ls];
            ls++;
            t++;
        } else {
            a[t] = a_right[rs];
            rs++;
            t++;
        }
    }
    while (ls < leftsz) {
        a[t] = a_left[ls];
        ls++;
        t++;
    }
    while (rs < rightsz) {
        a[t] = a_right[rs];
        rs++;
        t++;
    }
    return;
}
signed main() {
    int n;
    scanf("%d", &n);
    int * arr = (int*) ::malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
    */
}
