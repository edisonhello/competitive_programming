#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005],sum[100005],ofs[100005],dta[100005];
bitset<100005> inclu[400],islgt;
vector<int> mem[100005],light,heavy;
vector<int> sect[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=0;i<m;++i){
        int z; cin>>z; mem[i].resize(z);
        for(int j=0;j<z;++j)cin>>mem[i][j];
        (z<=350?light:heavy).push_back(i);
        if(z<=350)islgt[i]=1;
    }
    for(int i=0;i<heavy.size();++i){
        for(int j:mem[heavy[i]]){
            inclu[i][j]=1;
            sum[heavy[i]]+=a[j];
        }
    }
    for(int i=0;i<m;++i){
        sect[i].resize(heavy.size());
        for(int j=0;j<heavy.size();++j){
            int cnt=0;
            for(int k:mem[i])if(inclu[j][k])++cnt;
            sect[i][j]=cnt;
        }
    }

    while(q--){
        char c; cin>>c;
        if(c=='?'){
            int x; cin>>x; --x;
            if(islgt[x]){
                ll ans=0;
                for(int i:mem[x]){
                    ans+=a[i];
                }
                for(int j=0;j<heavy.size();++j)ans+=dta[heavy[j]]*sect[x][j];
                cout<<ans<<endl;
            }
            else{
                ll ans=sum[x]+ofs[x];
                // for(int j=0;j<heavy.size();++j)ans+=ofs[heavy[j]]*sect[x][j];
                cout<<ans<<endl;
            }
        }
        else{
            int x,y; cin>>x>>y; --x;
            if(islgt[x]){
                for(int i:mem[x]){
                    a[i]+=y;
                }
                for(int i=0;i<heavy.size();++i){
                    ofs[heavy[i]]+=1ll*sect[x][i]*y;
                }
            }
            else{
                // ofs[x]+=1ll*y*int(mem[x].size());
                dta[x]+=y;
                for(int i=0;i<heavy.size();++i){
                    ofs[heavy[i]]+=1ll*sect[x][i]*y;
                }
                // cout<<"ofs["<<x<<"] add "<<y*int(mem[x].size())<<" become "<<ofs[x]<<endl;
            }
        }
    }
}
