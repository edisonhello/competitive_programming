#include<iostream>
#include<algorithm>
using namespace std;

int dp[16][16];

int main(){
    dp[1][2]=dp[2][1]=1;
    for(int i=3;i<16;++i){
        dp[1][i]=dp[i][1]=1;
    }
    for(int i=2;i<15;++i){
        for(int j=i;j<15;++j){

        }
    }

    int n,m;
    while(cin>>n>>m,n){
        if((n*m)&1){
            cout<<"0\n";
            continue;
        }
        if(m>n)swap(n,m);
        cout<<dp[m][n]<<endl;
    }
}
