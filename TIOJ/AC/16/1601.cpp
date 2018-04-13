#include<bits/stdc++.h>
using namespace std;

int mp[222][222];
bool ok[222],used[222];

int main(){
    int n,m,ks=0; while(cin>>n>>m){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>mp[i][j];
            }
        }
        int ans=max(n*2,m*2);
        auto meow=[&](){
            memset(ok,0,sizeof(ok));
            memset(used,0,sizeof(used));
            for(int i=2;i<m;++i)ok[i]=1;
            for(int $=2;$<n;++$){
                int mx=-1,id=-1;
                for(int i=2;i<n;++i){
                    if(used[i])continue;
                    int c=0;
                    for(int j=2;j<m;++j){
                        if(ok[j] && mp[i][j])++c;
                    }
                    if(c>mx)mx=c,id=i;
                }
                for(int i=2;i<m;++i){
                    ok[i]&=mp[id][i];
                }
                ans=max(ans,(mx+2+$+1)*2);
                used[id]=1;
            }
        };
        meow();
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=m;++j){
                swap(mp[i][j],mp[j][i]);
            }
        }
        swap(n,m);
        meow();
        cout<<"Case "<<(++ks)<<": ";
        cout<<ans<<endl;
    }
}
