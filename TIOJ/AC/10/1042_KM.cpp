#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int128 __int128

ostream& operator<<(ostream &ostm,const __int128 &val){if(!val){ostm<<"0"; return ostm;}__int128 cpy=val; stack<int> st; while(cpy)st.push(cpy%10),cpy/=10; while(st.size())ostm<<st.top(),st.pop();return ostm;}

bitset<108> vx,vy;
int n,match[105];
long long w[105][105],llable[105],rlable[105],dw;

bool find(int x){
    vx[x]=1;
    for(int i=1;i<=n;++i){
        if(vy[i] || w[x][i]==-1)continue;
        ll ww=llable[x]+rlable[i]-w[x][i];
        if(!ww){
            vy[i]=1;
            if(!match[i] || find(match[i])){
                match[i]=x;
                return 1;
            }
        } else dw=min(ww,dw);
    } return 0;
}

int main(){
    while(cin>>n,n){
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>w[i][j],w[i][j]=max(w[i][j],0ll);
        // for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<w[i][j]<<" ";cout<<endl;}cout<<endl;
        memset(llable,0,sizeof(llable)); memset(rlable,0,sizeof(rlable));
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)llable[i]=max(llable[i],w[i][j]);
        memset(match,0,sizeof(match));
        bool keep=1;
        for(int i=1;i<=n && keep;++i){
            while("jizz"){
                vx.reset(); vy.reset();
                dw=5000000000000000000ll;
                if(find(i))break;
                if(dw==5000000000000000000ll){keep=0; break;}
                for(int i=1;i<=n;++i){
                    if(vx[i])llable[i]-=dw;
                    if(vy[i])rlable[i]+=dw;
                }
            }
        }
        int128 ans=0;
        for(int i=1;i<=n;++i)ans+=w[match[i]][i];
        // for(int i=1;i<=n;++i)cout<<"match["<<i<<"] is "<<match[i]<<" with processed val "<<wmax+10-w[match[i]][i]<<endl;
        cout<<ans<<endl;
    }
}
