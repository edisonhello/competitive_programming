#include<bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define uint uint_fast64_t

using namespace std;


const uint table[3] = {0x9e3779b185ebca87, 0xc2b2ae3d27d4eb4f, 0x165667b19e3779f9};

inline uint Mix(uint a, uint b) {
  a += b * table[1];
  a = (a << 31) | (a >> 33);
  return a * table[0];
}

uint gcd(uint a, uint b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

uint PRNG(uint a, uint b) {
  uint v1 = Mix(-table[0], a);
  uint v2 = Mix(table[1], b);
  uint ret = ((v1 << 18) | (v1 >> 46)) + ((v2 << 7) | (v2 >> 57));
  ret ^= ret >> 33;
  ret *= table[1];
  ret ^= ret >> 29;
  ret *= table[2];
  ret ^= ret >> 32;
  return ret;
}

int main(){
    int n; long long a,b,c=0,g; scanf("%d%llu%llu\n",&n,&a,&b);
    g=gcd(a,b);
    while(n--){
        a=PRNG(b,g);
        b=PRNG(a,g);
        c=PRNG(c,g);
        g=gcd(a,b);
        cout<<g<<endl;
    }
    printf("%llu\n",c);
}
