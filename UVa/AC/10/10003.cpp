#include<bits/stdc++.h>
using namespace std;

int ct[55],dpa[55][55],len[55];

int dp(int l,int r){
    if(dpa[l][r])return dpa[l][r];
    if(l+1==r)return 0;
    int mn=0x3f3f3f3f;
    for(int i=l+1;i<r;++i){
        mn=min(dp(l,i)+dp(i,r),mn);
    }
    return dpa[l][r]=mn+ct[r]-ct[l];
}

int main(){
    int l; while(cin>>l,l){
        memset(dpa,0,sizeof(dpa));
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>ct[i+1]; ct[1]=0; ct[n+2]=l;
        // for(int i=1;i<=n+2;++i)cout<<ct[i]<<" "; cout<<endl;
        // for(int i=1;i<=n+1;++i)len[i]=ct[i+1]-ct[i];
        // for(int i=1;i<=n+1;++i)cout<<len[i]<<" "; cout<<endl;
        n+=2;
        cout<<"The minimum cutting is ";
        cout<<dp(1,n)<<".\n";
    }
}
