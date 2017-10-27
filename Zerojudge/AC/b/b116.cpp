#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int m,n,a[105],dp[105][50005],t;

int main(){
    while(cin>>m>>n){
        while(m--){
            MS0(a);
            t=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                t+=a[i];
            }
            if(t&1){
                cout<<"No\n";
                continue;
            }
            MS0(dp);
            for(int i=0;i<n;i++){
                for(int j=0;j<=t/2;j++){
                    if(j>=a[i]){
                        dp[i+1][j]=max(dp[i][j],dp[i][j-a[i]]+a[i]);
                    }
                    else{
                        dp[i+1][j]=dp[i][j];
                    }
                }
            }
            // cout<<dp[n][t/2]<<" ";
            if(t/2==dp[n][t/2]){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }

}
