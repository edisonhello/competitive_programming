#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int128 __int128

bitset<1003> vx,vy;
int n,match[1003];
ll L,U,dd[1003],nd[1003],w[1003][1003],slack[1003],xv[1003],yv[1003];

bool dfs(int x){
    vx[x]=1;
    for(int i=1;i<=n;++i){
        if(vy[i])continue;
        ll t=xv[x]+yv[i]-w[x][i];
        if(t==0){
            vy[i]=1;
            if(!match[i] || dfs(match[i])){
                match[i]=x;
                return 1;
            }
        }
        else slack[i]=min(slack[i],t);
    } return 0;
}

int main(){
    int t; cin>>t; while(t--){
        int k; cin>>n>>L>>U>>k;
        vector<pair<int,int>> no(k);
        for(auto &i:no){
            cin>>i.first>>i.second;
        }
        for(int i=1;i<=n;++i)cin>>dd[i];
        for(int i=1;i<=n;++i)cin>>nd[i];
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=max(min(dd[i]+nd[j],U),L)-L;
        ll mx=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)mx=max(mx,w[i][j]);
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=mx-w[i][j];
        for(auto &i:no){
            w[i.first][i.second]=-4000000000000000000ll;
        }
        memset(xv,0,sizeof(xv)); memset(yv,0,sizeof(yv));
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)xv[i]=max(xv[i],w[i][j]);
        memset(match,0,sizeof(match));
        for(int i=1;i<=n;++i){
            while("jizz"){
                vx.reset(); vy.reset();
                memset(slack,0x3f,sizeof(slack));
                if(dfs(i))break;
                ll mn=4000000000000000000ll;
                for(int i=1;i<=n;++i)if(!vy[i])mn=min(mn,slack[i]);
                for(int i=1;i<=n;++i){
                    if(vx[i])xv[i]-=mn;
                    if(vy[i])yv[i]+=mn;
                }
            }
        }
        bool ok=1;
        for(auto &i:no){
            if(match[i.second]==i.first)ok=0;
        }
        if(!ok)cout<<"no"<<endl;
        else{
            int128 ans=0;
            for(int i=1;i<=n;++i)ans+=mx-w[match[i]][i];
            if(!ans)cout<<0<<endl;
            else{
                stack<int> st;
                while(ans){
                    st.push(ans%10);
                    ans/=10;
                }
                while(st.size()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<endl;
            }
        }
    }
}
