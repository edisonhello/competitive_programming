#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
#define ll long long

int dp[1005];
bool ap[1005];

void init(){
    dp[1]=1,dp[2]=2;
    for(int i=3;i<200;++i){
        memset(ap,0,sizeof(ap));
        for(int j=0;j<=i-j-1;++j){
            ++ap[dp[j]^dp[i-j-1]];
        }
        for(int j=0;j<=i-j-2;++j){
            ++ap[dp[j]^dp[i-j-2]];
        }
        int ptr=0;
        while(ap[ptr])++ptr;
        dp[i]=ptr;
    }
}
int gt(ll in){
    if(in<=70)return dp[in];
    else return dp[(in-70-1)%60+70+1];
}

int main(){
    init();
    /*for(int i=1;i<=200;++i){
        cout<<setw(3)<<gt(i);
        if(!(i%10))cout<<endl;
    }*/
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        int val=0;
        while(n--){
            ll in;cin>>in;
            val^=gt(in);
        }
        if(val)cout<<"F"<<endl;
        else cout<<"S"<<endl;
    }
}
