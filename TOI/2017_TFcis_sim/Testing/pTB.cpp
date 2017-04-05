#include<iostream>
using namespace std;
#include<cmath>

bool dfs(int now,int lft){
    int mx=(int)sqrt(now);
    if(now==0 && lft==0)return 1;
    if(now && lft==0)return 0;
    for(int i=mx;i>=0;--i){
        if(dfs(now-i*i,lft-1)){
            cout<<i<<" ";
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;cin>>n;
    dfs(n,4);
}
