#include<bits/stdc++.h>
#define ld long double
using namespace std;
struct atk{int m,d;};
int w,b,n,m;
atk a[1005];
int dp[10005];
int main(){
    int ts;cin>>ts;
    while(ts--){
        cin>>w>>b>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            int _a,d;
            cin>>_a>>d;
            a[i]={_a,d};
        }
        cin>>m;
        for(int i=0;i<n;i++){
            a[i].m+=m;
        }
        w+=m;
        for(int i=0;i<n;i++){
            for(int j=a[i].m;j<=w;j++){
                dp[j]=max(dp[j],dp[j-a[i].m]+a[i].d);
            }
        }
        for(int i=w-1;i>=0;i--){
            if(dp[w]>=b){
                cout<<"Yes\n";
                goto nxt;
            }
        }
        cout<<"No\n";
        nxt:;
    }
}
