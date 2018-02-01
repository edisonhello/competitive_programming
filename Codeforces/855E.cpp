#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ccnt[11];
ll cnt(int b,ll l,ll r){
    ll rt=0;
    for(ll i=l;i<=r;++i){
        memset(ccnt,0,sizeof(ccnt));
        ll ii=i;
        while(ii){
            ++ccnt[ii%b];
            ii/=b;
        }
        bool ok=1;
        for(int i=0;i<b;++i){
            if(ccnt[i]&1)ok=0;
        }
        if(ok)++rt;
    } return rt;
}

int meow[100];


ll dp[63][1024];
ll full(int b,int dig){
    for(int i=0;i<=dig;++i)for(int j=0;j<(1<<b);++j)dp[i][j]=0;
    for(int k=1;k<b;++k)dp[1][1<<k]=1;
    for(int i=1;i<dig;++i){
        for(int j=0;j<(1<<b);++j){
            for(int k=0;k<b;++k){
                dp[i+1][j^(1<<k)]+=dp[i][j];
            }
        }
    }
    return dp[dig][0];
}
ll dp2[2][63][1024];
ll half(ll up,int b,int dig){
    // cout<<"call half "<<up<<endl;
    for(int i=0;i<=dig;++i)for(int j=0;j<(1<<b);++j)dp2[0][i][j]=dp2[1][i][j]=0;
    ll base=1; int k;
    for(int i=1;i<dig;++i)base*=b;
    for(k=1;k<b && base*2<=up;++k)dp2[0][1][1<<k]=1,up-=base; dp2[1][1][1<<k]=1; up-=base;
    // cout<<"k: "<<k<<endl;
    base/=b;
    for(int i=1;i<dig;++i){
        for(int j=0;j<(1<<b);++j){
            for(int k=0;k<b;++k){
                dp2[0][i+1][j^(1<<k)]+=dp2[0][i][j];
                if(base*(k+1)<=up)dp2[0][i+1][j^(1<<k)]+=dp2[1][i][j];
                else if(base*k<=up)dp2[1][i+1][j^(1<<k)]+=dp2[1][i][j];
            }
        }
        up-=up/base*base;
        base/=b;
    }
    return dp2[0][dig][0]+dp2[1][dig][0];
}

ll cnt(int b,ll x){
    ll upp=b-1,rt=0,dig=1;
    while(upp<=x){
        ++dig;
        ++upp; upp*=b; --upp;
        // cout<<"dig: "<<dig<<" , upp: "<<upp<<endl;
        if(dig&1)continue;
        if(upp>x || upp<0){
            rt+=half(x,b,dig);
            break;
        }
        else rt+=full(b,dig);
    }
    return rt;
}

int main(){
    int ts; cin>>ts; while(ts--){
        int b; ll l,r;
        cin>>b>>l>>r;
        cout<<cnt(b,r)-cnt(b,l-1)<<endl;
    }
}
