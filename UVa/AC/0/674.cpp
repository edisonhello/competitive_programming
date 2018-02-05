#include<bits/stdc++.h>
using namespace std;

int dp[7979],coin[5]={1,5,10,25,50};

void init(){
    dp[0]=1;
    for(int i=0;i<5;++i){
        for(int j=coin[i];j<7979;++j){
            dp[j]+=dp[j-coin[i]];
        }
    }
}

int main(){
    init();
    int n; while(cin>>n){
        cout<<dp[n]<<endl;
    }
}
