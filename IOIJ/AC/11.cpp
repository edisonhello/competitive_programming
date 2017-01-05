#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
typedef long long LL;
#define lgll(x) (63-__builtin_clzll(x))
const int N=100100;
int A[64],B[64];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        FOR(i,64) A[i] = ((a&(1LL<<i))!=0);
        FOR(i,64) B[i] = ((b&(1LL<<i))!=0);
        int atop,btop;
        for(atop=63;A[atop]==0;atop--);
        for(btop=63;B[btop]==0;btop--);
        if(atop!=btop) {
            cout << (1l<<lgll(b)+1)-1 << " " << 0 << endl;
        }
        else {
            int top=atop;
            while(top>=0 && A[top]==B[top])top--;
            b=(b>>(top+1))<<(top+1);
            cout << b+((1l<<top+1)-1) << " " << b << endl;
        }
    }
    return 0;
}
