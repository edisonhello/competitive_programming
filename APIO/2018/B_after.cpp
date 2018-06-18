#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,tune=native")
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
 
int n,pos[300005],ans[300005];
struct circle{
    int x,y,r,i;
} c[300005];
 
namespace std {
    template<> struct hash<pair<int,int>> {
        long long operator()(const pair<int,int> &a) const {
            return 1ll*a.first*1000000009+a.second;
        }
    };
}
 
unordered_map<pair<int,int>,int> mp;
vector<int> idxs[300005];
 
int rit(){
    char c; int x=0; bool mi=0;
    while((c=getchar_unlocked())){ if(c=='-' || (c>='0' && c<='9'))break; }
    if(c=='-')mi=1;
    else x=c-'0';
    while((c=getchar_unlocked())){ if(c<'0' || c>'9')break; x=x*10+(c&15); }
    return mi?-x:x;
}
 
int main(){
    n=rit();
    for(int i=0;i<n;++i){
        c[i].x=rit(),c[i].y=rit(),c[i].r=rit();
        c[i].i=i+1;
    }
    sort(c,c+n,[](const circle &a,const circle &b){ return a.r==b.r?a.i<b.i:a.r>b.r; });
    // for(int i=0;i<n;++i)pos[c[i].i]=i;
    int masterPtr=0;
    int D=c[0].r,killcount=0;
 
    auto buildGraph=[&](){
        for(int i=1;i<=int(mp.size());++i)idxs[i].clear();
        mp.clear();
        D=c[masterPtr].r;
        killcount=0;
        for(int i=masterPtr;i<n;++i){
            if(c[i].i==0)continue;
            pair<int,int> pos(c[i].x/D,c[i].y/D);
            int &it=mp[pos];
            if(it)idxs[it].push_back(i);
            else idxs[(it=mp.size())].push_back(i);
            // cout<<"insert "<<i<<" into "<<it<<" , pos: "<<pos.first<<" , "<<pos.second<<endl;
        }
    };
 
    buildGraph();
    while(masterPtr<n){
        while(masterPtr<n && c[masterPtr].i==0)++masterPtr;
        if(masterPtr>=n)break;
        // cout<<"now masterPtr: "<<masterPtr<<" circle is "<<c[masterPtr].i<<endl;
        // cout<<"circle position: "<<c[masterPtr].x<<" "<<c[masterPtr].y<<endl;
        if(D/c[masterPtr].r>=5 && killcount>=1000){
            buildGraph();
            // cout<<"map contains: "<<endl;
            // for(auto p:mp)cout<<"[("<<p.first.first<<" , "<<p.first.second<<") : "<<p.second<<"] ";
            // cout<<endl;
        }
        pair<int,int> pos(c[masterPtr].x/D,c[masterPtr].y/D);
        // cout<<"base position: "<<pos.first<<" "<<pos.second<<endl;
        for(int dx=-2;dx<=2;++dx){
            for(int dy=-2;dy<=2;++dy){
                auto it=mp.find(make_pair(pos.first+dx,pos.second+dy));
                if(it==mp.end())continue;
                // cout<<"it's not the end: "<<it->second<<endl;
                for(int i:idxs[it->second]){
                    if(c[i].i==0)continue;
                    if(1ll*(c[i].x-c[masterPtr].x)*(c[i].x-c[masterPtr].x)+1ll*(c[i].y-c[masterPtr].y)*(c[i].y-c[masterPtr].y)>1ll*(c[masterPtr].r+c[i].r)*(c[masterPtr].r+c[i].r))continue;
                    ans[c[i].i]=c[masterPtr].i;
                    // cout<<"killed "<<c[i].i<<", killer: "<<c[masterPtr].i<<endl;
                    
                    if(c[i].i!=c[masterPtr].i)c[i].i=0;
                    ++killcount;
                }
            }
        }
        c[masterPtr].i=0;
    }
    for(int i=1;i<=n;++i){
        printf("%d ",ans[i]);
    }
}
// AC
