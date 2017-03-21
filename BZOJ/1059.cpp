#include<bits/stdc++.h>
using namespace std;
int mp[222][222];

int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>mp[i][j];
        for(int i=0;i<n;++i){
            bool has1=0;
            for(int j=0;j<n;++j){
                if(mp[i][j])has1=1;
            }
            if(!has1){
                cout<<"No\n";
                goto nextDT;
            }
        }
        for(int i=0;i<n;++i){
            bool has1=0;
            for(int j=0;j<n;++j){
                if(mp[j][i])has1=1;
            }
            if(!has1){
                cout<<"No\n";
                goto nextDT;
            }
        }
        cout<<"Yes\n";
        nextDT:;
    }
}
