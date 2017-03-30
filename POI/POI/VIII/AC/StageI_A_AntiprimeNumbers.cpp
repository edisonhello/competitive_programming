#include<bits/stdc++.h>
using namespace std;

#define ll long long

int countin(int n){
    int ans=1;
    for(int i=2;i*i<=n;++i){
        int cnt=0;
        while(n%i==0)n/=i,++cnt;
        ans*=cnt+1;
    } if(n!=1)ans*=2;
    return ans;
}
int jizz[1234],len;
int main(){
    int mxp=0,dist=1,prv=0;
    for(ll i=1;i<=2000000000;i+=dist){
        int fs=countin(i);
        if(fs>mxp){
            jizz[len++]=i;
            mxp=fs;
            prv=i;
        }
        if(i==10){ i=6, dist=6; }
        if(i==60){ dist=60; }
        if(i==2520){ dist=2520; }
        if(i==166320){ dist=55440; }
    }
    int n;cin>>n;
    int* it=upper_bound(jizz,jizz+len,n); --it;
    cout<<(*it)<<endl;
}
// AC
