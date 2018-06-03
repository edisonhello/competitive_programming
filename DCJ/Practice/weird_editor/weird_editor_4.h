// Sample input 1, in CPP.

#include <cassert>
#include <cstdlib>

int dig[]={4,4,5,5,6,6,7,7,8,8};

long long GetNumberLength() {
  srand(14331);
  return 10LL;
}

long long GetDigit(long long i) {
  if(i>=GetNumberLength())assert(0);
  return dig[i];
}
