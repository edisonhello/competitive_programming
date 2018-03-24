#ifndef LIB2056J_H_INCLUDED
#define LIB2056J_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <cmath>
#include <iostream>
int n, *p, *q, *r, qc, qnow, limit;
bool *v;

void AC() { puts("Yeah you got an AC"); exit(0); }
void WA() { puts("No you got a WA"); exit(0); }

void generate_permutation() {
    while (true) {
        std::random_shuffle(p, p + n);
        memset(v, false, sizeof(bool) * n);
        bool valid = true;
        for (int i = 0; i < n; ++i) if (!v[i]) {
            int cycle_length = 0;
            int now = 0;
            while (!v[now]) v[now] = true, ++cycle_length, now = p[now];
            valid &= (cycle_length <= n / 2);
        }
        if (valid) break;
    }
}

int Init() {
    srand(time(nullptr));
    double rat;
    scanf("%d %lf", &n, &rat);
    p = new int[n]; q = new int[n]; v = new bool[n];
    for (int i = 0; i < n; ++i) p[i] = i, q[i] = i;
    generate_permutation();
    std::random_shuffle(q, q + n);
    qc = 0; qnow = 0;
    limit = ceil(rat * n);
    printf("%d\n", limit);
    return n;
}

int Query(int pos) {
    if (pos < 0 || pos >= n) WA();
    ++qc;
    if (qc > limit) WA();
    return p[pos];
}

void Answer(int pos) {
    if (p[pos] != qnow) WA();
    qc = 0;
    qnow++;
    if (qnow >= n) AC();
    r = new int[n];
    for (int i = 0; i < n; ++i) r[i] = p[i];
    for (int i = 0; i < n; ++i) p[q[i]] = q[r[i]];
    for (int i = 0; i < n; ++i) printf("%2d ",i); std::cout << std::endl;
    for (int i = 0; i < n; ++i) printf("%2d ",p[i]); std::cout << std::endl;
    delete r; 
}

#endif


