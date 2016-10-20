#include<bits/stdc++.h>
using namespace std;
int th[25][25],n;
int sf[2097200];
int dp(int now){
    if(now==0)return 0;
    if(sf[now])return sf[now];
    int mn=(1<<30);
    for(int i=1,ii=0;i<1<<n;i<<=1,++ii){
        if(now&i){
            for(int j=(i<<1),jj=ii+1;j<1<<n;j<<=1,++jj){
                if(now&j){
                    for(int k=(j<<1),kk=jj+1;k<1<<n;k<<=1,++kk){
                        if(now&k){
                            mn=min(mn,dp(now^i^j^k)+th[ii][jj]+th[jj][kk]+th[kk][ii]);
                        }
                    }
                }
            }
            break;
        }
    }
    return sf[now]=mn;
}

int main(){
    ios_base::sync_with_stdio(0);

    int ts;cin>>ts;while(ts--){
        memset(th,0,sizeof(th));
        memset(sf,0,sizeof(sf));
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>th[i][j];
            }
        }
        //cout<<inr[0];
        int now=(1<<n)-1;
        cout<<dp(now)<<'\n';
    }
}
