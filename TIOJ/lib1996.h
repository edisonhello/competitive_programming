#ifndef LIB1996_H_INCLUDED
#define LIB1996_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void init(int, int, int[], int[], int[]);
int get_cost(int);

int main()
{
    int *A, *B, *K;
    int N, M, Q, i;
    scanf("%d%d%d", &N, &M, &Q);
    A = (int*)malloc(sizeof(int) * M);
    B = (int*)malloc(sizeof(int) * M);
    K = (int*)malloc(sizeof(int) * M);
    for (i = 0; i < M; i++) scanf("%d%d%d", A + i, B + i, K + i);
    init(N, M, A, B, K);
    while (Q--) {
        scanf("%d", &i);
        printf("%d\n", get_cost(i));
    }
}

#endif // LIB1996_H_INCLUDED
