#include<bits/stdc++.h>
using namespace std;

int mem[111][111];
int cnt[111];
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>mem[i][j];
        }
        int mx=0;
        for(int j=0;j<n;++j){
            mx=max(mx,mem[i][j]);
        }
        for(int j=0;j<n;++j){
            if(mem[i][j]==mx){
                ++cnt[j];
                break;
            }
        }
    }
    int mx=0;
    for(int i=0;i<m;++i){
        mx=max(mx,cnt[i]);
    }
    for(int i=0;i<m;++i){
        if(cnt[i]==mx){
            cout<<i+1<<endl;
            exit(0);
        }
    }
}
