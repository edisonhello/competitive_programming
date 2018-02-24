#ifndef LIB2013_H_INCLUDED
#define LIB2013_H_INCLUDED

#include <stdio.h>

void init(int);
void explore(int, int);
int run(int, int);

int main()
{
  int N, Q;
  scanf("%d%d", &N, &Q);
  init(N);
  while (Q--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 2) printf("%d\n", run(b, c));
    else explore(b, c);
  }
}

#endif // LIB2013_H_INCLUDED
