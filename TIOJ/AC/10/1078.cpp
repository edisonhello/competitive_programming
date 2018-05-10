#include<bits/stdc++.h>
using namespace std;

long long C[77][77];

long long dfs(long long n,int ptr,long long now,int cnt1,int cnt0){
    if(ptr<0)return now<=n && cnt1>cnt0;
    // cout<<"dfs: "<<n<<" "<<ptr<<" "<<now<<" "<<cnt1<<" "<<cnt0<<endl;
    long long rt=0;
    if((now|(1ll<<ptr))<=n){
        rt+=dfs(n,ptr-1,now|(1ll<<ptr),cnt1+1,cnt0);
        int le=ptr;
        // cout<<"in now ptr: "<<ptr<<" , rt: "<<rt<<endl;
        if(now)for(int i=0;i<=le;++i){
            if(cnt0+(le-i)+1>=cnt1+i)continue;
            rt+=C[le][i];
        }
        // cout<<"after run, rt: "<<rt<<endl;
    }
    else rt+=dfs(n,ptr-1,now,cnt1,cnt0+1);
    return rt;
}

long long bf(long long n){
    long long rt=0;
    for(long long i=1;i<=n;++i){
        int c1=0,c0=0;
        for(int j=0;;++j){
            if((1ll<<j)>i)break;
            if(i&(1ll<<j))++c1;
            else ++c0;
        }
        // if(c1>c0){ ++rt; cout<<i<<" ok "<<endl; }
        if(c1>c0)++rt;
    }
    return rt;
}

int main(){
    C[0][0]=1;
    for(int i=1;i<77;++i)for(int j=0;j<=i;++j){
        C[i][j]=C[i-1][j];
        if(j)C[i][j]+=C[i-1][j-1];
    }
    // for(int i=0;i<4;++i)for(int j=0;j<=i;++j)cout<<i<<" "<<j<<" "<<C[i][j]<<endl;
    int t; cin>>t; while(t--){
        long long n; cin>>n;
        long long ans=0;
        for(int i=0;;++i){
            if((1ll<<i)>n)break;
            ans+=dfs(n,i,0,0,0);
            // cout<<"in i: "<<i<<" , ans: "<<ans<<endl;
        }
        // cout<<ans<<" "<<bf(n)<<endl;
        cout<<ans<<endl;
    }
}
