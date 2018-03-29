#include<bits/stdc++.h>
using namespace std;

int c[300005],sz[300005];
string s;
vector<int> G[300005];

struct node{
    node *ch[26];
    int sz;
    node():sz(1){
        memset(ch,0,sizeof(ch));
    }
};

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->sz<b->sz)swap(a,b);
    for(int i=0;i<26;++i){
        if(a->ch[i] && b->ch[i]){
            a->sz-=a->ch[i]->sz;
            a->ch[i]=merge(a->ch[i],b->ch[i]);
            a->sz+=a->ch[i]->sz;
        }
        else if(b->ch[i]){
            a->ch[i]=b->ch[i];
            a->sz+=a->ch[i]->sz;
        }
    }
    return a;
}
node *dfs(int now,int pa){
    // cout<<"dfs: "<<now<<" "<<pa<<endl;
    node *root=new node();
    for(int i:G[now]){
        if(i==pa)continue;
        if(root->ch[s[i]-'a'])root->sz-=root->ch[s[i]-'a']->sz;
        root->ch[s[i]-'a']=merge(root->ch[s[i]-'a'],dfs(i,now));
        root->sz+=root->ch[s[i]-'a']->sz;
    }
    sz[now]=root->sz;
    return root;
}

int main(){
    int n; cin>>n;   
    for(int i=0;i<n;++i)cin>>c[i];
    cin>>s;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0,0);
    int mx=0;
    for(int i=0;i<n;++i){
        mx=max(mx,c[i]+sz[i]);
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        if(mx==c[i]+sz[i])++cnt;
    }
    cout<<mx<<endl<<cnt<<endl;
}
