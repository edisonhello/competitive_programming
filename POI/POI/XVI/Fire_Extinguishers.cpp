#include<bits/stdc++.h>
using namespace std;
#define int long long

int k,s,ans;

vector<int> G[100005];
bitset<100005> cover;
int unc[100005][22],abil[100005][22];

void pifo(int x){
    cout<<"pifo x="<<x<<endl;
    cout<<"unc : "; for(int i=0;i<=k;++i)cout<<unc[x][i]<<" "; cout<<endl;
    cout<<"abil: "; for(int i=0;i<=k;++i)cout<<abil[x][i]<<" "; cout<<endl;
}

void dfs(int now,int pa){
    // cout<<"now in dfs "<<now<<endl;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
        for(int j=0;j<k;++j){
            unc[now][j+1]+=unc[i][j];
            abil[now][j]+=abil[i][j+1];
        }
    }
    // pifo(now);
    unc[now][0]+=1;
    for(int i=k;i>=0;--i){
        int mn=min(unc[now][i],abil[now][i]);
        unc[now][i]-=mn;
        abil[now][i]-=mn;
        if(i){
            mn=min(unc[now][i-1],abil[now][i]);
            abil[now][i]-=mn;
            unc[now][i-1]-=mn;
        }
    }
    while(unc[now][k]>0){
        ++ans;
        int power=s,ptr=k;
        while(power>0 && ptr>=k-1){
            if(unc[now][ptr]>=power){
                unc[now][ptr]-=power;
                power=0;
            }
            else{
                power-=unc[now][ptr];
                unc[now][ptr]=0;
                --ptr;
            }
        }
        if(power>0)abil[now][k]+=power;
    }
    // pifo(now);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n>>s>>k; 
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    for(int i=k;i>=0;--i){
        for(int j=i;j>=0;--j){
            int mn=min(abil[1][i],unc[1][j]);
            abil[1][i]-=mn;
            unc[1][j]-=mn;
        }
    }
    // pifo(1);
    int ptr=k;
    while(ptr>=0){
        if(unc[1][ptr]>0){
            ++ans;
            int power=s;
            while(power>0 && ptr>=0){
                if(unc[1][ptr]>=power){
                    unc[1][ptr]-=power;
                    power=0;
                }
                else{
                    power-=unc[1][ptr];
                    unc[1][ptr]=0;
                    --ptr;
                }
            }
        }
        else --ptr;
    }
    cout<<ans<<endl;
}
