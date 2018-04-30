#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> G[80008],bG[80008];
ll v[80008],val,ans;
int pa[80008],nowc,mxc;

void dfs(int now,ll upp){
    if((1<<now)&nowc){
        if(v[now]>=upp){
            val=(-(1ll<<60));
            return;
        }
        else{
            val+=v[now];
            upp=v[now];
        }
    }
    for(int i:G[now]){
        dfs(i,upp);
    }
}

vector<ll> num;

ll bit[88888];
int bid[88888],to[88888];;
void add(int x,ll v,int id){
    for(;x<88888;x+=x&-x){
        // bit[x]=max(bit[x],v);
        if(v>bit[x]){
            bit[x]=v;
            bid[x]=id;
        }
    }
}
pair<ll,int> qry(int x,ll v=0,int id=-1){
    for(;x;x-=x&-x){
        if(bit[x]>v){
            v=bit[x];
            id=bid[x];
        }
    }
    return make_pair(v,id);
}

void dfs1(int now){
    for(int i:G[now]){
        dfs1(i);
    }
    int x=lower_bound(num.begin(),num.end(),v[now])-num.begin()+1;
    auto rt=qry(x-1);
    to[now]=rt.second;
    add(x,rt.first+v[now],now);
}


void meow(int n){
    for(int i=0;i<n;++i)num.push_back(v[i]);
    sort(num.begin(),num.end());
    ll ans=0;
    set<int> take;
    for(int i:G[0]){
        dfs1(i);
        int x=lower_bound(num.begin(),num.end(),v[0])-num.begin()+1;
        auto rt=qry(x-1);
        ans+=rt.first;
        while(i){
            take.insert(i);
            i=to[i];
        }
        memset(bit,0,sizeof(bit));

    }
    ans+=v[0];
    take.insert(0);
    cout<<ans<<endl;
    for(int i:take)cout<<i+1<<" ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    for(int i=1;i<n;++i){
        cin>>pa[i],--pa[i];
        G[pa[i]].push_back(i);
        bG[i].push_back(pa[i]);
        bG[pa[i]].push_back(i);
    }
    {
        int is_path=1;
        int c1=0,c2=0;
        for(int i=0;i<n;++i){
            if(bG[i].size()==1u)++c1;
            else if(bG[i].size()==2u)++c2;
            else is_path=0;
        }
//        cout<<is_path<<endl;
        if(is_path)meow(n),exit(0);
        if(n>=30)exit(0);
    }
    for(nowc=1;nowc<(1<<n);++nowc){
        if(nowc&1); else continue;
        val=0;
        dfs(0,1ll<<60);
        if(val>ans)ans=val,mxc=nowc;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;++i){
        if(mxc&(1<<i))cout<<i+1<<" ";
    }
    cout<<endl;

}
