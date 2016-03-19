#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline int rit(){
    int t=0,k=1;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}


int main(){
    ll t=rit();
    while(t--){
        ll n=rit(),k=rit(),l=rit();
        ll p[n+2],f[n+2],b[n+2];
        memset(p,0,sizeof(p));
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(b));

        for(int i=1;i<=n;i++)p[i]=rit();

        p[0]=0;f[0]=0;p[n+1]=l;b[n+1]=0;ll ans=((ll)1<<60);
        for(int i=1;i<=n;i++)f[i]=(i-k>=0?f[i-k]+p[i]:p[i])+min(p[i],l-p[i]);
        for(int i=n;i>=1;i--)b[i]=(i+k<=n+1?b[i+k]+l-p[i]:l-p[i])+min(p[i],l-p[i]);
        for(int i=0;i<=n;i++)ans=min(ans,f[i]+b[i+1]);
        printf("%lld\n",ans);
    }

}
