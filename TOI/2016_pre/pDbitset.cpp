#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;

int a[10005];
bitset<2000005> dp;

int main(){
    int n,tot=0,tott;cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        tot+=a[i];
    }
    tott=tot;
    tot>>=1;
    dp[0]=1;

    for(int i=0;i<n;++i)dp=(dp)|(dp<<a[i]);
    for(;tot>=0;--tot)if(dp[tot])break;
    cout<<tot<<" "<<tott-tot<<endl;
}
