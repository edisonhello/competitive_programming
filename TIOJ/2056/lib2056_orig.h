#ifndef LIB2056J_H_INCLUDED
#define LIB2056J_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <cmath>
#include <iostream>

int t, n, *p, *q, *r, qc, qnow, limit, win, lose, qt;
double rat, winning_percentage;
bool *v, correct;

void AC() { puts("Yeah you got an AC"); }
void WA() { puts("No you got a WA"); }
void Win() { ++win; }
void Lose() { ++lose; }

/* void generate_permutation() {
    while (true) {
        std::random_shuffle(p, p + n);
        memset(v, false, sizeof(bool) * n);
        bool valid = true;
        for (int i = 0; i < n; ++i) if (!v[i]) {
            int cycle_length = 0;
            int now = i;
            while (!v[now]) v[now] = true, ++cycle_length, now = p[now];
            valid &= (cycle_length <= limit);
        }
        if (valid) break;
    }
} */

int Testcase() {
    srand(time(nullptr));
    scanf("%d", &t);
    scanf("%d %lf %lf", &n, &rat, &winning_percentage);
    qt = 0;
    return t;
}

int Init() {
    ++qt;
    p = new int[n]; q = new int[n]; v = new bool[n];
    for (int i = 0; i < n; ++i) p[i] = i, q[i] = i;
    std::random_shuffle(q, q + n);
    std::random_shuffle(p, p + n);
    qc = 0; qnow = 0;
    limit = ceil(rat * n);
    // printf("%d\n", limit);
    // generate_permutation();
    correct = true;
    return n;
}

int Query(int pos) {
    if (pos < 0 || pos >= n) correct = false;
    ++qc;
    if (qc > limit) correct = false;
    return p[pos];
}

void Answer(int pos) {
    if (p[pos] != qnow) correct = false;
    // else if (p[pos] == qnow && correct) Win();
    qnow++;
    if (qnow == n) {
        if (correct) Win();
        else Lose();
        if (qt == t) {
            double percentage = 1.0 * win / (win + lose);
            if (percentage >= winning_percentage) AC();
            else WA();
            exit(0);
        }
        delete p; delete q; delete v;
        p = nullptr; q = nullptr; v = nullptr;
        return;
    }
    qc = 0;
    r = new int[n];
	std::random_shuffle(q, q + n);
    for (int i = 0; i < n; ++i) r[i] = p[i];
    for (int i = 0; i < n; ++i) p[q[i]] = q[r[i]];
    // for (int i = 0; i < n; ++i) printf("%2d ",i); std::cout << std::endl;
    // for (int i = 0; i < n; ++i) printf("%2d ",p[i]); std::cout << std::endl;
    delete r; 
}

#endif



