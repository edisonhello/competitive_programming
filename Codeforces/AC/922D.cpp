#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll inans[100005];
int s[100005],h[100005];
int a[100005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        a[i]=i;
        string str; cin>>str;
        ll cnts=0;
        for(char c:str){
            if(c=='h')inans[i]+=cnts,++h[i];
            else ++cnts,++s[i];
        }
    }
    sort(a,a+n,[](const int &a,const int &b){
        return 1ll*s[a]*h[b]>1ll*s[b]*h[a];
    });
    ll cnts=0,ans=0;
    for(int i=0;i<n;++i){
        ans+=inans[i];
        ans+=1ll*h[a[i]]*cnts;
        cnts+=s[a[i]];
    }
    cout<<ans<<endl;
}
