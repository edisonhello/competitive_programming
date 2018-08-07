#include <stdio.h>
#include <stdlib.h>
#include "grader.h"

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_SIZE 1000000000
#define MAX_N 100000

int main() {
	int R, C, N;
    int P, Q, U, V;
    long long K;
    int i, type;
	int res;

	res = scanf("%d", &R);
	if (res != 1)
		fail("Failed to read R from input file.");
	if (R < 1 || R > MAX_SIZE)
		fail("R is out of bounds.");

	res = scanf("%d", &C);
	if (res != 1)
		fail("Failed to read C from input file.");
	if (C < 1 || C > MAX_SIZE)
		fail("C is out of bounds.");

	res = scanf("%d", &N);
	if (res != 1)
		fail("Failed to read N from input file.");
	if (N < 0 || N > MAX_N)
		fail("N is out of bounds.");

    init(R, C);

	for (i = 0; i < N; i++) {
        res = scanf("%d", &type);
        if (type == 1) {
		    res = scanf("%d%d%lld", &P, &Q, &K);
            update(P, Q, K);
        } else if (type == 2) {
		    res = scanf("%d%d%d%d", &P, &Q, &U, &V);
            printf("%lld\n", calculate(P, Q, U, V));
        } else
			fail("Invalid action type in input file.");
	}

	return 0;
}
