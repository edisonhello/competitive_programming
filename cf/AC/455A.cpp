#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

inline ll rit(){
    ll t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

ll n,a[100005],t,i,dp[100005];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit();
    for(i=0;i<n;i++){
        t=rit();
        a[t]++;
    }
    dp[1]=a[1];
    dp[2]=a[2]*2;
    for(i=3;i<=100003;i++){
        dp[i]=max(max(dp[i-1],dp[i-2]+a[i]*i),dp[i-3]+a[i]*i);
    }
    cout<<dp[100003]<<endl;
}
