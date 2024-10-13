#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const long long maxn = 100000;
const long long INF = 1e9;
const long long p = 101;
const long long mod = 1e9 + 7;
const int inf = 1200000000;
void swap(int* a, int* b) {
    int tmp = (*a);
    *a = *b;
    *b = tmp;
}
int a[maxn]{inf};
void shiftup(int tec) {
    if (tec == 0) {
        return;
    }
    int pred = (tec-1)/2;
    if (a[pred] > a[tec]) {
        swap(&a[pred], &a[tec]);
        shiftup(pred);
    }
}
void shiftdown(int v) {
    int smaller = v;
    if (2*v+1 < maxn) {
        if (a[2*v+1] < a[v]) {
            smaller = 2*v+1;
        }
    }
    if (2*v+2 < maxn) {
        if (a[2*v+2] < a[smaller]) {
            smaller = 2*v+2;
        }
    }
    if (smaller!=v) {
        swap(&a[smaller], &a[v]);
        shiftdown(smaller);
    }
}
int t = 0;
void insert(int node) {
    a[t] = node;
    shiftup(t);
    t++;
}
int extract_min() {
    int ans = a[0];
    a[0] = inf;
    shiftdown(0);
    return ans;
}
signed main() {
    for (int i = 0; i < maxn; i++) {
        a[i] = inf;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }
    for (int i = 0; i < n; i++) {
        int ans = extract_min();
        printf("%d ", ans);
    }
    /*
    5
    2 5 2 1 3
    1 2 2 3 5
    */
}
