#include<bits/stdc++.h>
using namespace std;

string mp[103];
int pos[103][103];

int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i)for(int j=0;j<n;++j){
        if(i+k<=n){
            bool ok=1;
            for(int ii=0;ii<k;++ii)if(mp[i+ii][j]=='#')ok=0;
            if(ok)for(int ii=0;ii<k;++ii)++pos[i+ii][j];
        }
        if(j+k<=n){
            bool ok=1;
            for(int jj=0;jj<k;++jj)if(mp[i][j+jj]=='#')ok=0;
            if(ok)for(int jj=0;jj<k;++jj)++pos[i][j+jj];
        }
    }
    /* for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<pos[i][j]<<" ";
        }
        cout<<endl;
    } */
    int mx=0;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)mx=max(mx,pos[i][j]);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(pos[i][j]==mx){ cout<<i+1<<" "<<j+1<<endl; exit(0); }
}
