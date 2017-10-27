#include<iostream>
using namespace std;
unsigned long long ans[45],dp[876];
void init(){
    dp[0]=1;
    for(int i=1;i<41;++i){
        for(int j=850;j>=i;--j){
            dp[j]+=dp[j-i];
        }
        // cout<<"i="<<i<<" , dp:";
        // for(int j=1;j<=30;++j)cout<<dp[j]<<" ";cout<<endl;
        // cout<<i*(i+1)/2<<endl;
        if(!((i*(i+1)/2)&1))ans[i]=dp[i*(i+1)/4];
    }
}
int main(){
    init();
    int n;while(cin>>n)cout<<(ans[n]/2)<<endl;
}
