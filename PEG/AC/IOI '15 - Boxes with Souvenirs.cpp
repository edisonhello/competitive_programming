#include<bits/stdc++.h>

using namespace std;

#define ll long long

inline int rit(){
    int t=0,k=1;char a;
    do{
        a=getchar();
        if(a=='-')k=-1;
    }while(a<'0'||a>'9');
    do{
        t=t*10+a-'0';
        a=getchar();
    }while(a>='0'&&a<='9');
    return t*k;
}

int main(){
        int n=rit(),k=rit(),l=rit();
        vector<ll> p,f,b;
        p.clear();p.resize(n+2);
        f.clear();f.resize(n+2);
        b.clear();b.resize(n+2);
        for(int i=1;i<=n;i++)p[i]=rit();
        p[0]=0;f[0]=0;
        for(int i=1;i<=n;i++)f[i]=(i-k>=0?(f[i-k]+p[i]):p[i])+min(p[i],l-p[i]);
        p[n+1]=l;b[n+1]=0;
        for(int i=n;i>=1;i--)b[i]=(i+k<=n+1?(b[i+k]+l-p[i]):l-p[i])+min(p[i],l-p[i]);
        ll ans=((ll)1<<60);
        for(int i=0;i<=n;i++)ans=min(ans,f[i]+b[i+1]);
        cout<<ans<<endl;
}
