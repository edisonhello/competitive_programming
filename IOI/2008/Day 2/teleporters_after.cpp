#include<bits/stdc++.h>
using namespace std;

pair<int,int> pt[1000006];
#define oppo(i,x) ((x)==pt[i].first?pt[i].second:pt[i].first)
#define is(i,x) ((x)==pt[i].first?0:1)
int occu[2000006];
vector<pair<int,int>> bl;
int to[4000006],rev[4000006];
bitset<4000006> v;

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>pt[i].first>>pt[i].second;
    for(int i=1;i<=n;++i)occu[pt[i].first]=occu[pt[i].second]=i;
    for(int i=1;i<=n;++i){
        to[pt[i].first*2]=pt[i].second*2+1;
        to[pt[i].second*2]=pt[i].first*2+1;
    }
    for(int i=1,j;i<=2000000;i=j){
        if(!occu[i]){ j=i+1; continue; }
        while(!occu[++j]);
        to[i*2+1]=j*2;
    }
    for(int i=1;i<=2000000;++i)if(occu[i]){ to[0]=i*2; break; }
    for(int i=2000000;i>=1;--i)if(occu[i]){ to[i*2+1]=1; break; }
    memset(rev,0xff,sizeof(rev));
    for(int i=1;i<=4000001;++i)if(to[i])rev[to[i]]=i;

    int ans=0;
    for(int z=0;z!=1;ans+=((!(z&1)) && (to[z]&1)),z=to[z]); // cout<<"z: "<<z<<endl;
    for(int z=0;z!=1;z=to[z],v[z]=1);
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=3;i<=4000001;i+=2){
        if(v[i])continue;
        if(rev[i]==-1)continue;
        v[i]=1;
        int c=0;
        for(int z=i;z!=i || c==0;c+=((!(z&1)) && (rev[z]&1)),z=rev[z],v[z]=1);
        pq.push(c+2);
        // cout<<"start from "<<i<<" pq add "<<c+2<<endl;
    }
    // cout<<"no add, ans: "<<ans<<endl;
    while(m>0 && pq.size()){
        ans+=pq.top(),pq.pop(),--m;
    }
    while(m>1)m-=2,ans+=4;
    while(m>0)--m,++ans;
    cout<<ans<<endl;
}
// one submission AC
