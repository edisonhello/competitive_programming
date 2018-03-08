#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll p=47017,mod=1000000007;
ll pp[200006],hsh[200006],ihsh[200006];
int a[200006];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    pp[0]=1;
    for(int i=1;i<=200005;++i)pp[i]=pp[i-1]*p%mod;
    for(int i=1;i<=n;++i)hsh[i]=(hsh[i-1]+pp[i-1]*a[i]%mod)%mod;
    for(int i=n;i>=1;--i)ihsh[i]=(ihsh[i+1]+pp[n-i]*a[i]%mod)%mod;
    
    vector<int> ans; int mxdif=0;
    for(int len=1;len<=n;++len){
        if(len*2>n){
            if(mxdif==1)ans.push_back(len);
        }
        else{
            set<ll> exi; int cnt=0;
            for(int i=1,j=len;j<=n;i+=len,j+=len){
                ll hh=(hsh[j]-hsh[i-1]+mod)%mod*pp[n-j]%mod;
                ll ihh=(ihsh[i]-ihsh[j+1]+mod)%mod*pp[i-1]%mod;
                if(exi.find(hh)!=exi.end())continue;
                exi.insert(hh);
                exi.insert(ihh);
                ++cnt;
            }
            if(cnt>mxdif){
                mxdif=cnt;
                ans.clear();
            }
            if(cnt==mxdif){
                ans.push_back(len);
            }
        }
    }
    cout<<mxdif<<" "<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" ";
}
