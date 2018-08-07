#include <stdio.h>
#include <stdlib.h>
#include "grader.h"

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_A 50000
#define MAX_B 50000
#define MAX_T 1000000

static int X[MAX_A];
static int Y[MAX_B];
static int W[MAX_T];
static int S[MAX_T];

int main() {
    int A, B, T, i;
	int res;

	res = scanf("%d", &A);
	if (res != 1)
		fail("Failed to read A from input file.");
	if (A < 0 || A > MAX_A)
		fail("A is out of bounds.");

	res = scanf("%d", &B);
	if (res != 1)
		fail("Failed to read B from input file.");
	if (B < 0 || B > MAX_B)
		fail("B is out of bounds.");

	res = scanf("%d", &T);
	if (res != 1)
		fail("Failed to read T from input file.");
	if (T < 1 || T > MAX_T)
		fail("T is out of bounds.");

	for (i = 0; i < A; i++) {
		res = scanf("%d", &X[i]);
		if (res != 1)
		    fail("Failed to read data from input file.");
    }
	for (i = 0; i < B; i++) {
        res = scanf("%d", &Y[i]);
        if (res != 1)
            fail("Failed to read data from input file.");
    }
	for (i = 0; i < T; i++) {
        res = scanf("%d%d", &W[i], &S[i]);
        if (res != 2)
            fail("Failed to read data from input file.");
    }

	int answer = putaway(A, B, T, X, Y, W, S);

	printf("%d\n", answer);

	return 0;
}
