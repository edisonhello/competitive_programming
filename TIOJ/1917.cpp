#include<bits/stdc++.h>
using namespace std;
#define long __int128
#define ll long long
#define int128 __int128

ostream& operator<<(ostream &ostm,const __int128 &val){if(!val){ostm<<"0"; return ostm;} bool mns=0; __int128 cpy=(val<0?mns=1,-val:val); stack<char> st; while(cpy)st.push(cpy%10+'0'),cpy/=10; if(mns)st.push('-'); while(st.size())ostm<<st.top(),st.pop(); return ostm;}

bitset<1008> vx,vy;
int n,match[1005];
int128 L,U,daydng[1005],ngtdng[1005];
int128 w[1005][1005],llable[1005],rlable[1005],dw;
vector<pair<int,int>> forbid;
bool print;

bool find(int x){
    if(print)cout<<"find: x = "<<x<<endl;
    vx[x]=1;
    for(int i=1;i<=n;++i){
        if(vy[i] || w[x][i]==-1)continue;
        int128 ww=llable[x]+rlable[i]-w[x][i];
        if(ww==0){
            vy[i]=1;
            if(!match[i] || (!vx[match[i]] && find(match[i]))){
                match[i]=x;
                return 1;
            }
        } 
        else if(ww>0)dw=min(ww,dw);
        else assert(false);
    } return 0;
}

int main(){
    int t; cin>>t; while(t--){
        auto lll=1ll,uuu=1ll;
        int k; cin>>n>>lll>>uuu>>k;
        L=lll,U=uuu;
        forbid.clear(); forbid.resize(k);
        for(auto &i:forbid)cin>>i.first>>i.second;
        for(int i=1;i<=n;++i)cin>>lll,daydng[i]=lll;
        for(int i=1;i<=n;++i)cin>>lll,ngtdng[i]=lll;
        memset(w,0,sizeof(w));
        int128 wmax=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=max(min(daydng[i]+ngtdng[j],U),L)-L,wmax=max(wmax,w[i][j]);
        // for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<w[i][j]<<" ";cout<<endl;}cout<<endl;
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=wmax+10-w[i][j];
        // for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<w[i][j]<<" ";cout<<endl;}cout<<endl;
        for(auto &i:forbid)w[i.first][i.second]=-1;
        for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<w[i][j]<<" ";cout<<endl;}cout<<endl;
        memset(llable,-1,sizeof(llable)); memset(rlable,0,sizeof(rlable));
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)llable[i]=max(llable[i],w[i][j]);
        memset(match,0,sizeof(match));
        bool keep=1;
        for(int i=1,vircnt=0;i<=n && keep;++i,vircnt=0){
            cout<<"alive when i: "<<i<<endl;
            if(i==6)print=1;
            while("jizz"){
                // ++vircnt; if(vircnt>=6*n){keep=0; break;}
                vx.reset(); vy.reset();
                dw=4500000000000000000ll;
                if(find(i))break;
                if(dw==4500000000000000000ll){keep=0; break;}
                for(int i=1;i<=n;++i){
                    if(vx[i])llable[i]-=dw;
                    if(vy[i])rlable[i]+=dw;
                }
                if(!print)continue;
                cout<<"dw: "<<dw<<endl;
                cout<<"llable: "; for(int i=1;i<=n;++i)cout<<llable[i]<<" "; cout<<endl;
                cout<<"rlable: "; for(int i=1;i<=n;++i)cout<<rlable[i]<<" "; cout<<endl;
                cout<<"match: "; for(int i=1;i<=n;++i)cout<<match[i]<<" "; cout<<endl;
                static int dwcb2=0;
                if(dw==2)++dwcb2;
                if(dwcb2>=8)return 7122;
            }
        }
        if(!keep)cout<<"no"<<endl;
        else{
            int128 ans=0;
            for(int i=1;i<=n;++i)ans+=wmax+10-w[match[i]][i];
            // for(int i=1;i<=n;++i)cout<<"match["<<i<<"] is "<<match[i]<<" with processed val "<<wmax+10-w[match[i]][i]<<endl;
            cout<<ans<<endl;
        }
    }
}
