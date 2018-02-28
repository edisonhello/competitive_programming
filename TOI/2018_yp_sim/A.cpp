#include<bits/stdc++.h>
using namespace std;

bitset<1004> notPrime;
vector<int> prime;
void init(){
    notPrime[1]=1;
    for(int i=2;i<1004;++i){
        if(notPrime[i])continue;
        prime.push_back(i);
        for(int j=i*i;j<1004;j+=i){
            notPrime[j]=1;
        }
    }
}

bool isPrime(int x){
    for(int i:prime){
        if(i*i>x)break;
        if(x%i==0)return 0;
    }
    return 1;
}

int a[100005];
vector<int> minpos[1000006];
bitset<1000006> vis;

void relate_in(queue<pair<int,int>> &q,int v,int step){
    int v_back=v;
    for(int i:prime){
        if(i*i>v)break;
        if(v%i)continue;
        if(vis[v_back/i])continue;
        q.emplace(v_back/i,step);
        vis[v_back/v]=1;
        while(v%i==0)v/=i;
    }
    if(v!=1 && !vis[v_back/v])q.emplace(v_back/v,step),vis[v_back/v]=1;
    v=v_back;
    for(int i:prime){
        if(v*i>1000000)break;
        if(vis[v*i])continue;
        vis[v*i]=1;
        q.emplace(v*i,step);
    }
}

pair<int,int> get(int val,int index){
    vis.reset();
    queue<pair<int,int>> q;
    relate_in(q,val,1);
    int ansstep=9999999,ansindex;
    while(q.size()){
        if(q.front().second>ansstep)break;
        if(minpos[q.front().first].size()){
            if(minpos[q.front().first][0]==index){
                if(minpos[q.front().first].size()>1)tie(ansstep,ansindex)=min(make_pair(ansstep,ansindex),make_pair(q.front().second,minpos[q.front().first][1]));
            }
            else tie(ansstep,ansindex)=min(make_pair(ansstep,ansindex),make_pair(q.front().second,minpos[q.front().first][0]));
        }
        relate_in(q,q.front().first,q.front().second+1);
        q.pop();
    }
    return make_pair(ansstep,ansindex);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    for(int i=1004;i<500000;++i)if(isPrime(i))prime.push_back(i);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        minpos[a[i]].push_back(i);
    }
    for(int i=1;i<=n;++i){
        auto ans=get(a[i],i);
        cout<<ans.first<<" "<<ans.second<<'\n';
    }
}
