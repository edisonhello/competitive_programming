#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
int n,m;
vector<pii> G[10003];
bitset<10003> ined;
int dist[10003];
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m && n){
        for(int i=0;i<10003;i++)G[i].clear();
        ined.reset();
        memset(dist,0,sizeof(dist));
        ans=0;
        for(int i=0;i<m;i++){
            int z,x,c;
            cin>>z>>x>>c;
            G[z].push_back({x,c});
            G[x].push_back({z,c});
        }
        memset(dist,0x7f,sizeof(dist));
        dist[1]=0;
        for(int ppp=0;ppp<n;ppp++){
            int nowc=-1,noww=0x7f7f7f7f;
            for(int i=1;i<=n;i++){
                if(!ined[i] && dist[i]<noww){
                    nowc=i;
                    noww=dist[i];
                }
            }
            if(nowc==-1){
                break;
            }
            // cout<<"join:nowc:"<<nowc<<endl;
            ined[nowc]=1;
            ans+=noww;
            for(int i=0;i<(int)G[nowc].size();i++){
                if(!ined[G[nowc][i].X] && G[nowc][i].Y < dist[G[nowc][i].X]){
                    dist[G[nowc][i].X]=G[nowc][i].Y;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!ined[i]){
                cout<<"-1\n";
                goto jizz;
            }
        }
        cout<<ans<<endl;
        jizz:;
    }
}
