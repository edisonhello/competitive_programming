#include<bits/stdc++.h>
using namespace std;
#define lock _my_lock

int n,m;
int p2[1000006];

int main(){
    cin>>n>>m;
    string s; cin>>s;
    p2[0]=1; for(int i=1;i<=n;++i)p2[i]=(p2[i-1]<<1)%m;
    int ans=0,pre=0,mx=0,mn=0;
    for(int i=1;i<=n;++i){
        if(s[i-1]=='P'){
            int tpre=pre+1,tmx=max(mx,tpre),tmn=min(mn,tpre);
#define get(a,b) (p2[(((a)+((b)==1))>>1)])
            if(tmn>=0 && tmx<=2)(ans+=get(n-i,tpre))%=m;
            if(tmn>=-1&& tmx<=1)(ans+=get(n-i,tpre+1))%=m;
            if(tmn>=-2&& tmx<=0)(ans+=get(n-i,tpre+2))%=m;
            if(tmn>=0 && tmx<=1)--ans;
            if(tmn>=-1&& tmx<=0)--ans;

            // cout<<"in "<<i<<" add to "<<ans<<endl;
        }
        if(s[i-1]=='L')++pre; else --pre;
        mx=max(mx,pre); mn=min(mn,pre);
    }
    cout<<(ans+1+m)%m<<endl;
}
// in virtual 20
// after AC
// simplified
