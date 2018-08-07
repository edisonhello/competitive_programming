#include "graderlib.c"

int main() {
    int N;
	N = init();
	exploreCave(N);
    printf("INCORRECT\nYour solution did not call answer().\n");
	return 0;
}
