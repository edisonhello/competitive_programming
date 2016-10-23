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

int dp[1005];
int v[]={1,5,10,30,50,70,100,110,500,1000};
int t=10;

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    for(int i=0;i<10;i++){
        for(int j=v[i];j<=1000;j++){
            dp[j]=min(dp[j],dp[j-v[i]]+1);
        }
    }
    int ts;
    cin>>ts;
    while(ts--){
        ll n;cin>>n;
        cout<<(n/1000+dp[n%1000])<<endl;
    }
}
