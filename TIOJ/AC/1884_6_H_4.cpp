#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int rit(){
int n=0,k=1;char c;do{c=getchar();if(c=='-')k=-1;}while(c<'0'||c>'9');
do{n=n*10+c-'0';c=getchar();}while(c>='0'&&c<='9');return n*k;}

int main(){
int t=rit();while(t--){
int n=rit(),k=rit(),l=rit();vector<ll> p,f,b;p.clear();f.clear();b.clear();p.resize(n+2);f.resize(n+2);b.resize(n+2);
for(int i=1;i<=n;i++)p[i]=rit();p[0]=0;f[0]=0;b[n+1]=0;p[n+1]=l;
for(int i=1;i<=n;i++)f[i]=(i-k>=0?f[i-k]+p[i]:p[i])+min(p[i],l-p[i]);
for(int i=n;i>=1;i--)b[i]=(i+k<=n+1?b[i+k]+l-p[i]:l-p[i])+min(p[i],l-p[i]);
ll ans=((ll)1<<60);for(int i=0;i<=n;i++)ans=min(ans,f[i]+b[i+1]);cout<<ans<<endl;
}}
