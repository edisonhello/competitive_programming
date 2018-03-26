#include<bits/stdc++.h>
using namespace std;

vector<int> x;

void dfs(int now,int base,int lft){
    if(lft==0){
        x.push_back(now);
        return;
    }
    if(base==1000000000){
        return;
    }
    for(int i=0;i<min(10,lft+1);++i){
        dfs(now+base*i,base*10,lft-i);
    }
}

int main(){
    int k; cin>>k;
    dfs(0,1,10);
    sort(x.begin(),x.end());
    cout<<x[k-1];
}
