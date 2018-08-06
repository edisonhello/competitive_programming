#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "grader.h"

#define MAX_N 100000

static int A[MAX_N];
static int B[MAX_N];
static int T[MAX_N];

int _main(travelTimeFunction travelTime) {
	int N, M, L, i;

	assert(scanf("%d%d%d", &N, &M, &L) == 3);
	for (i = 0; i < M; i++)
		assert(scanf("%d%d%d", &A[i], &B[i], &T[i]) == 3);

	int answer = travelTime(N, M, L, A, B, T);
	printf("%d\n", answer);

	return 0;
}
