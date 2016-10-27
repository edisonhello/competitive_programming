#include<bits/stdc++.h>
using namespace std;
int m,n,a[105];
int d[105][10005];
int main(){
    cin>>m>>n;
    while(m--){
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        int t=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            t+=a[i];
        }
        if(t&1){cout<<"No\n";continue;}
        for(int i=0;i<n;++i){
            for(int j=0;j<=(t>>1);++j){
                if(j<a[i])d[i+1][j]=d[i][j];
                else{
                    d[i+1][j]=max(d[i][j],d[i][j-a[i]]+a[i]);
                }
            }
        }
        if(d[n][t>>1]==(t>>1))cout<<"Yes\n";
        else cout<<"No\n";
    }
}
