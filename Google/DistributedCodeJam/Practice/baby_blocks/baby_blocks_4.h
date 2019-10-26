// Sample input 1, in CPP.

#include <cassert>

long long GetNumberOfBlocks() {
  return 1000000000LL;
}

long long GetBlockWeight(long long i) {
  if((int)i<1000000000)return 1LL;
  else assert(0);
}
