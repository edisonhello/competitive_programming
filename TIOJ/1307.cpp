#include<iostream>
using namespace std;
#include<vector>
#include<bitset>
#include<cstring>
#include<set>
#include<queue>
#include<assert.h>
#include<algorithm>

vector<int> G[10005],ans;
bitset<10005> v;
set<int> s[2];
struct st{int n,d;};
queue<st> q;

int bfs(int s,int e){
    v.reset();while(q.size())q.pop();
    q.push({s,0});v[s]=1;
    while(q.size()){
        // cout<<"af"<<endl;
        if(q.front().n==e)return q.front().d;
        for(int i:G[q.front().n]){
            if(!v[i]){
                v[i]=1;
                q.push({i,q.front().d+1});
            }
        }
        q.pop();
    }
    return -1;
}

void getCt(int st,int id,int d,int add){
    v.reset();while(q.size())q.pop();
    q.push({st,0});v[st]=1;
    while(q.size()){
        // cout<<"Ae"<<endl;
        if(q.front().d==d)s[id].insert(q.front().n);
        else if(add && q.front().d==d+1){s[id].insert(q.front().n);q.pop();continue;}
        else if(q.front().d>d)break;
        for(int i:G[q.front().n]){
            if(!v[i]){
                v[i]=1;
                q.push({i,q.front().d+1});
            }
        }
        q.pop();
    }
}

void solve(int st,int ed,int n){
    s[0].clear();s[1].clear();
    // cout<<"aaa"<<endl;
    int dist=bfs(st,ed);
    if(!~dist)assert(1==0);
    // cout<<"aaf"<<endl;
    getCt(st,0,dist>>1,dist&1);
    getCt(ed,1,dist>>1,dist&1);
    // cout<<"nya"<<endl;
    ans.clear();
    ans.resize(n);
    auto it=set_intersection(s[0].begin(),s[0].end(),s[1].begin(),s[1].end(),ans.begin());
    ans.resize(it-ans.begin());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ts;cin>>ts;while(ts--){
        int n,q;cin>>n>>q;

        for(int i=1;i<=n;++i)G[i].clear();

        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while(q--){
            string s,t;int a,b;
            cin>>s>>a>>t>>b;
            cout<<s<<" and "<<t<<":";
            solve(a,b,n);
            for(int i:ans)cout<<" "<<i;
            cout<<endl;
        }
    }
}
