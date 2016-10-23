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

int dp[103][50001];
int m,a[103],t;

int main(){
    int ts;cin>>ts;
    while(ts--){
        cin>>m;
        t=0;
        for(int i=0;i<m;i++){
            cin>>a[i];
            t+=a[i];
        }
        MS0(dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<=t/2;j++){
                if(j>=a[i]){
                    dp[i+1][j]=max(dp[i][j],dp[i][j-a[i]]+a[i]);
                }
                else{
                    dp[i+1][j]=dp[i][j];
                }
            }
        }
        cout<<t-2*dp[m][t/2]<<endl;
    }
}
