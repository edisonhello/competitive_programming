#include<bits/stdc++.h>
using namespace std;
const int MX=100;
int n,m,q,mp[MX][MX];
bool gone[MX];
int ans=-1;
bool back=0;
bool _back=0;
priority_queue<pair<int,int> > que;

void go(int now,int dis,int far){
    if(now==dis){
        ans+=far;
        if(back)_back=1;
        back=1;
        return ;
    }
    gone[now] = 1;
    for(int i=1;i<=n;i++){
        if(mp[now][i]<321 && !gone[i]){
            que.push(make_pair(far+mp[now][i],i));
        }
    }
}

int main(){
    cin>>n>>m>>q;
    memset(mp,321,sizeof(mp));
    memset(gone,0,sizeof(gone));
    for(int i=0;i<m;i++){
        int a,b,f,k;cin>>a>>b>>f>>k;
        if(k==1||k==3){
            mp[a][b]=f;
        }
        if(k==2||k==3){
            mp[b][a]=f;
        }
    }
    for(int i=0;i<q;i++){
        int a,b,s;cin>>a>>b>>s;
        que.push(make_pair(0,a));
        while(que.size() && !(back)){
            int snd = que.top().second;
            int fst = que.top().first ;
            que.pop();
            go(snd,b,fst);
        }
        while(que.size()){
            que.pop();
        }
        que.push(make_pair(0,b));
        memset(gone,0,sizeof(gone));
        while(que.size() && !(_back)){
            int snd = que.top().second;
            int fst = que.top().first ; 
            que.pop();
            go(snd,a,fst);
        }
    }
    ans==-1 ? cout<<ans<<endl : cout<<ans+1<<endl;
}
