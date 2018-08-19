#include<bits/stdc++.h>
using namespace std;

bitset<35000> np;
vector<int> p;
void init(){
    for(int i=2;i<35000;++i){
        if(np[i])continue;
        p.push_back(i);
        for(int j=i*i;j<35000;j+=i)np[j]=1;
    }
}

map<int,int> decomp;
vector<int> factor,ans;

void dfs1(map<int,int>::iterator it,map<int,int> &mp,int now){
    // cout<<"dfs1 "<<(it==mp.end())<<endl;
    if(it==mp.end()){ factor.push_back(now); return; }
    // cout<<"dfs1 "<<now<<" , it: "<<it->first<<" "<<it->second<<endl;
    auto p=*it; ++it;
    for(int i=0;i<=p.second;++i){
        dfs1(it,mp,now);
        now*=p.first;
    }
}

void dfs2(int now,int pos,int add){
    if(now==1){ ans.push_back(add); return; }
    for(;pos>=1;--pos){
        int div=now/factor[pos];
        if(div*factor[pos]==now){
            dfs2(div,pos,add+factor[pos]-1);
        }
    }
}

int main(){
    init();
    int n; cin>>n;
    int x=n;
    for(int i:p){
        if(i*i>x)break;
        while(x%i==0)++decomp[i],x/=i;
    }
    if(x!=1)++decomp[x]; x=1;
    dfs1(decomp.begin(),decomp,1);
    sort(factor.begin(),factor.end());
    // for(int i:factor)cout<<i<<" ";  cout<<endl;
    dfs2(n,int(factor.size())-1,0);
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
