#include<bits/stdc++.h>
using namespace std;

string s;
short dp[10005][10005];
char cf[10005][10005];
bitset<10005> com[10005];

int go1(int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;
    if(com[l][r])return dp[l][r];
    com[l][r]=1;
    int _l=go1(l+1,r);
    int _r=go1(l,r-1);
    int _lr=(s[l]==s[r]?go1(l+1,r-1)+2:-7122);
    int mx=max(max(_l,_r),_lr);
    if(_lr==mx)cf[l][r]=3;
    else if(_l==mx)cf[l][r]=1;
    else cf[l][r]=2;
    return dp[l][r]=mx;
}

string go2(int l,int r){
    if(l==r)return string(1,s[l]);
    if(l>r)return "";
    if(cf[l][r]==1)return go2(l+1,r);
    if(cf[l][r]==2)return go2(l,r-1);
    return s[l]+go2(l+1,r-1)+s[r];
}

int cnt[255];
int main(){
    cin>>s;
    int n=int(s.size());
    if(n<10000){
        int mx=go1(0,n-1);
        cout<<go2(0,n-1)<<endl;
    }
    else{
        for(char c:s)++cnt[c];
        char c=max_element(cnt,cnt+255)-cnt;
        for(int i=0;i<1000;++i)cout<<c;
        cout<<endl;
    }
    // cout<<"mx: "<<mx<<endl;
}
