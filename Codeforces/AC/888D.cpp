#include<bits/stdc++.h>
using namespace std;

int wrong[6];

long long C(int n,int i){
    long long rt=1;
    for(int j=n;j>n-i;--j)rt*=j;
    for(int j=1;j<=i;++j)rt/=j;
    return rt;
}

int main(){
    wrong[0]=1;
    wrong[2]=1;
    wrong[3]=2;
    wrong[4]=9;
    int n,k; cin>>n>>k;
    long long ans=0;
    for(int i=0;i<=k;++i){
        ans+=C(n,i)*wrong[i];
    }
    cout<<ans<<endl;
}
