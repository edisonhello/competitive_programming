#include<bits/stdc++.h>
using namespace std;

int beatr[1500009],beatl[1500009];
int a[1500009],b[1500009];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("in","r",stdin);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
    for(int i=n;i>=1;--i){
        for(int j=i+1;j<=n;++j){
            bool win=0;
            if(a[i]>a[j] && b[i]>=b[j])win=1;
            else if(a[i]>=a[j] && b[i]>b[j])win=1;
            else break;
            if(win){
                ++beatr[i];
                if(beatr[j]){
                    beatr[i]+=beatr[j];
                    j+=beatr[j];
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i-1;j>=1;--j){
            bool win=0;
            if(a[i]>a[j] && b[i]>=b[j])win=1;
            else if(a[i]>=a[j] && b[i]>b[j])win=1;
            else break;
            if(win){
                ++beatl[i];
                if(beatl[j]){
                    beatl[i]+=beatl[j];
                    j-=beatl[j];
                }
            }
        }
    }
    // for(int i=1;i<=n;++i)cout<<beatl[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;++i)cout<<beatr[i]<<" "; cout<<endl;
    int mx=0;
    for(int i=1;i<=n;++i)mx=max(mx,beatl[i]+beatr[i]);
    cout<<mx<<endl;
}
