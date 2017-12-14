
#pragma GCC optimize ("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

bitset<500005> v;
vector<int> G[500005],iG[500005];
set<int> cG[500005];
int tp[500005],ppptr;

struct node{
    static node mem[5000000];
    node *ch[2];
    int sz,i;
    node():sz(0),i(0){memset(ch,0,sizeof(ch));}
    int gsz(int x){return ch[!!x]?ch[!!x]->sz:0;}
} *root,node::mem[5000000];
int ptr;
struct ouroVoros{
    void clear(node *now=root){
        if(!now)return;
        clear(now->ch[0]);
        clear(now->ch[1]);
        delete now;
    }
    void insert(int val,int idx,int dep=20,node *&now=root){
        if(!now)now=new (&node::mem[ptr++]) node();
        ++now->sz;
        if(dep==-1){now->i=idx; return;}
        insert(val,idx,dep-1,now->ch[!!(val&(1<<dep))]);
    }
    void getmax(int val,int sz,int idx,int dep=20,node *&now=root){
        if(!sz || !now)return;
        if(now->i){
            G[idx].push_back(now->i);
            iG[now->i].push_back(idx);
            return;
        }
        bool rev=val&(1<<dep);
        if(now->gsz(!rev)>=sz)getmax(val,sz,idx,dep-1,now->ch[!rev]);
        else{
            getmax(val,now->gsz(!rev),idx,dep-1,now->ch[!rev]);
            getmax(val,sz-now->gsz(!rev),idx,dep-1,now->ch[rev]);
        }
    }
    ouroVoros(){root=0;}
} trie;

int a[500005];
int l[500005],r[500005];
int *bel;
ll ccsum[500005];

void dfs1(int now){
    v[now]=1;
    for(int i:G[now]){
        if(!v[i])dfs1(i);
    }
    tp[ppptr++]=now;
}
void dfs2(int now,int cc){
    v[now]=1;
    ccsum[cc]+=a[now]; bel[now]=cc;
    for(int i:iG[now])if(!v[i])dfs2(i,cc);
}
ll dp[500005];
ll dfs3(int now){
    if(dp[now])return dp[now];
    for(int i:cG[now]){
        if(i==now)continue;
        dfs3(i);
        dp[now]=max(dp[now],dp[i]);
    }
    dp[now]+=ccsum[now];
    return dp[now];
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s; cin>>n>>s;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
    root=0;
    for(int i=1;i<=n;++i){
        trie.getmax(a[i],l[i],i);
        trie.insert(a[i],i);
    }
    ptr=0; root=0;
    for(int i=n;i>=1;--i){
        trie.getmax(a[i],r[i],i);
        trie.insert(a[i],i);
    }
    /*for(int i=1;i<=n;++i){
        for(int ii:G[i])cout<<ii<<" "; cout<<endl;
    }*/

    bel=l;

    for(int i=1;i<=n;++i){
        if(!v[i])dfs1(i);
    }
    // cout<<"dfs1ed"<<endl;
    v.reset(); int cc=0;
    for(int i=n-1;i>=0;--i){
        if(!v[tp[i]])dfs2(tp[i],++cc);
    }
    // for(int i=1;i<=n;++i)cout<<bel[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i){
        for(int ii:G[i]){
            // cout<<"s1"<<endl;
            // cout<<bel[i]<<" "<<bel[ii]<<endl;
            cG[bel[i]].insert(bel[ii]);
            // cout<<"s2"<<endl;
        }
    }
    cout<<dfs3(bel[s])<<'\n';
}
