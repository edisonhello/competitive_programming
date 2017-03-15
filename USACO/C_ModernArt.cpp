#include<bits/stdc++.h>
using namespace std;
#define y1 ifsidofiein
#define y2 sorinvlwe

string mp[11];
int x1[11],y1[11],x2[11],y2[11];
int ind[11];bool app[11];

int main(){
    freopen("art.in","r",stdin);
    freopen("art.out","w",stdout);
    int n;cin>>n;for(int i=0;i<n;++i){
        cin>>mp[i];
        for(char &c:mp[i])c-='0';
    }
    for(int i=0;i<=9;++i)x1[i]=y1[i]=11,x2[i]=y2[i]=-1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            x1[mp[i][j]]=min(x1[mp[i][j]],i);
            y1[mp[i][j]]=min(y1[mp[i][j]],j);
            x2[mp[i][j]]=max(x2[mp[i][j]],i);
            y2[mp[i][j]]=max(y2[mp[i][j]],j);
        }
    }
    for(int ii=1;ii<=9;++ii){
        if(x1[ii]!=11){
            app[ii]=1;
            for(int i=x1[ii];i<=x2[ii];++i){
                for(int j=y1[ii];j<=y2[ii];++j){
                    if(mp[i][j]!=ii)++ind[mp[i][j]];
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=9;++i){
        if(app[i]&&!ind[i]){
            // cout<<ind[i]<<" "<<i<<endl;
            ++ans;
        }
    } cout<<ans<<endl;
}
