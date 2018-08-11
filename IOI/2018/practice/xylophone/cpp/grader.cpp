#include <cstdio>
#include <cstdlib>
#include "xylophone.h"

static const int N_MAX = 5000;
static const int Q_MAX = 10000;
static int N;
static int A[N_MAX];
static bool used[N_MAX];
static int query_c;
static int answer_c;

int ask(int s, int t) {
	if(query_c >= Q_MAX) {
		printf("Wrong Answer\n");
		exit(0);
	}
	query_c++;
	if(!(0 <= s && s <= t && t < N)) {
		printf("Wrong Answer\n");
		exit(0);
	}
	int mx = -1, mn = N;
	for(int i = s; i <= t; i++) {
		if(mx < A[i]) {
			mx = A[i];
		}
		if(mn > A[i]) {
			mn = A[i];
		}
	}
    printf("ask %d to %d get %d\n",s,t,mx-mn);
	return mx - mn;
}

void answer(int i, int a) {
	answer_c++;
    printf("answer %d is %d\n",i,a);
	if(!(0 <= i && i < N)) {
		printf("Wrong Answer\n");
		exit(0);
	}
	if(!(0 <= a && a < N)) {
		printf("Wrong Answer\n");
		exit(0);
	}
	if(used[i]) {
		printf("Wrong Answer\n");
		exit(0);
	}
	if(a != A[i]) {
		printf("Wrong Answer\n");
		exit(0);
	}
	used[i] = true;
}

int main() {
	query_c = 0;
	answer_c = 0;
	if(scanf("%d", &N) != 1) {
		fprintf(stderr, "Error while reading input\n");
		exit(1);
	}
	for(int i = 0; i < N; i++) {
		if(scanf("%d", A + i) != 1) {
			fprintf(stderr, "Error while reading input\n");
			exit(1);
		}
		used[i] = false;
	}
	detect_pitch(N);
	if(!(answer_c == N)) {
		printf("Wrong Answer\n");
		exit(0);
	}
	printf("Accepted : %d\n", query_c);
}
