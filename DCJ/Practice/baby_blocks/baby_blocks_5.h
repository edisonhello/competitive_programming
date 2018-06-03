// Sample input 1, in CPP.

#include <cassert>
#include <cstdlib>

long long GetNumberOfBlocks() {
  srand(clock());
  return 1000000000LL;
}

long long GetBlockWeight(long long i) {
  if((int)i<1000000000)return rand();
  else assert(0);
}
