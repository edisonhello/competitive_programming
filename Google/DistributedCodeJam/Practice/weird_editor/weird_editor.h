// Sample input 1, in CPP.

#include <cassert>
#include <cstdlib>

int dig[]={1,4,3,5,6,1};

long long GetNumberLength() {
  srand(14331);
  return 6LL;
}

long long GetDigit(long long i) {
  if(i>=GetNumberLength())assert(0);
  return dig[i];
}
