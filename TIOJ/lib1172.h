#ifndef LIBTEST_H_INCLUDED
#define LIBTEST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


    int* a;
    int n;
    int* d;
    int l;
    int* ans;
    int cnt = 0;

int comp(int x, int y)
{
    cnt++;
    if(cnt > 20000000) puts("Limit exceeded!!");
    if(x < 0 || y < 0 || x >= n || y >= n) puts("Out of range!!");
    if(a[x] != a[y]) return (a[x] < a[y]);
    return x < y;
}

void query(int n, int d[], int l, int ans[]);

int main()
{
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    scanf("%d", &l);
    d = (int*)malloc(sizeof(int) * l);
    ans = (int*)malloc(sizeof(int) * l);
    for(int i = 0; i < l; i++) scanf("%d", d+i);
    query(n, d, l, ans);
    for(int i = 0; i < l; i++) printf("%d ", ans[i]);
    return 0;
}

#endif
