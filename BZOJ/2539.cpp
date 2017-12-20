#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<bitset>
#include<cstring>
using namespace std;

int n,match[100];
bitset<100> vx,vy;
long long x[100],y[100],w[100][100],xv[100],yv[100],slack[100];
map<string,int> mp;

bool dfs(int x){
    vx[x]=1;
    for(int i=1;i<=n;++i){
        if(vy[i])continue;
        long long t=xv[x]+yv[i]-w[x][i];
        if(!t){
            vy[i]=1;
            if(!match[i] || dfs(match[i])){
                match[i]=x;
                return 1;
            }
        }
        else slack[i]=min(slack[i],t);
    } return 0;
}
int main(){
    long long k; scanf("%lld\n%d\n",&k,&n);
    for(int i=1;i<=2*n;++i){
        string s;
        scanf("%d %d",&x[i],&y[i]); cin>>s;
        for(int i=0;i<s.size();++i)if(s[i]<97)s[i]+=32;
        mp[s]=i;
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=1;
    string s1,s2;
    while(cin>>s1,s1!="End"){
        int val;
        cin>>s2;
        scanf("%d",&val);
        for(int i=0;i<s1.size();++i)if(s1[i]<97)s1[i]+=32;
        for(int i=0;i<s2.size();++i)if(s2[i]<97)s2[i]+=32;
        int id1=mp[s1],id2=mp[s2];
        if(id1>id2)swap(id1,id2); id2-=n;
        w[id1][id2]=val;
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        long long ijd=(y[j+n]-y[i])*1ll*(y[j+n]-y[i])+(x[j+n]-x[i])*1ll*(x[j+n]-x[i]);
        if(ijd>k*k)w[i][j]=-20000000000000ll;
        for(int k=1;k<=2*n;++k){
            if(k==i || k==j+n)continue;
            long long ikd=(y[k]-y[i])*1ll*(y[k]-y[i])+(x[k]-x[i])*1ll*(x[k]-x[i]);
            long long kjd=(y[j+n]-y[k])*1ll*(y[j+n]-y[k])+(x[j+n]-x[k])*1ll*(x[j+n]-x[k]);
            if(abs(sqrt(ikd)+sqrt(kjd)-sqrt(ijd))<1e-8){w[i][j]=-200000000000ll; break;}
        }
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)xv[i]=max(xv[i],w[i][j]);
    for(int i=1;i<=n;++i){
        while("jizz"){
            vx.reset(); vy.reset();
            memset(slack,0x3f,sizeof(slack));
            if(dfs(i))break;
            long long mn=0x3f3f3f3f3f3f3f3f;
            for(int i=1;i<=n;++i)if(!vy[i])mn=min(mn,slack[i]);
            for(int i=1;i<=n;++i){
                if(vx[i])xv[i]-=mn;
                if(vy[i])yv[i]+=mn;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=w[match[i]][i];
    }
    printf("%d\n",ans);
}
