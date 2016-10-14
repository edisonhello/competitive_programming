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

int m,n,ks;
short dp[1005][1005][12][2];
string ms,ns;

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n>>ks>>ms>>ns;
    m='M'+m;n='N'+n;
    for(int k=1;k<=ks;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(m[i]==n[j]){
                    if(m[i]=='a'){
                        dp[i][j][k][1]=max(dp[i-1][j-1][k][1]+1,dp[i-1][j-1][k-1][0]+1);
                    }
                    else{
                        dp[i][j][k][1]=dp[i-1][j-1][k][1];
                    }
                    dp[i][j][k][0]=max(dp[i-1][j-1][k][0])///jizzzzz///
                }
                else{

                }
            }
        }
    }
}
