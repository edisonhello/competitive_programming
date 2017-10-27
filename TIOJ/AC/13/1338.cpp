#ifndef WEAK
#include "lib1338.h"
#else
int main(){}
#endif
#include<utility>
#include<algorithm>
using namespace std;
#define X first
#define Y second
#define ll long long
#define ld long double
#define vint vector<int>
#define pii pair<long long,long long>
#define MS0(x) memset((x),0,sizeof(x))

pii sp[20][1000006];

void init(int n, long long C[]){
    for(int i=0;i<n;++i)sp[0][i].X=sp[0][i].Y=C[i];
    for(int i=1,k=1,j;i<n;i<<=1,++k){
        for(j=0;i+j<=n-i;j++){
            sp[k][j].X=min(sp[k-1][j].X,sp[k-1][j+i].X);
            sp[k][j].Y=__gcd(sp[k-1][j].Y,sp[k-1][j+i].Y);
        }
    }
}
int query(int l,int r){
    int D=31-__builtin_clz(r-l);
    return __gcd(sp[D][l].Y,sp[D][r-(1<<D)].Y)==min(sp[D][l].X,sp[D][r-(1<<D)].X);
}
