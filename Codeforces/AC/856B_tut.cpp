#include<bits/stdc++.h>
using namespace std;

int node_id;
bitset<1000006> v;
vector<int> G[1000006];
int dpa[1000006][2];

struct node{
    node *ch[26],*fail;
    int dp[2],id,dep;
    node(){
        id=++node_id;
        dep=0;
        dp[0]=dp[1]=0;
        memset(ch,0,sizeof(ch));
    }
} *root;

void build(node *&now,int ptr,string &s,int dep){
    if(!now)now=new node();
    now->dep=dep;
    if(ptr>=s.size())return;
    // cout<<"new node id "<<now->id<<" , at "<<s<<"["<<ptr<<"]"<<endl;
    build(now->ch[s[ptr]-'a'],ptr+1,s,dep+1);
    // now->dep=now->ch[s[ptr]-'a']->dep+1;
    // now->ch[s[ptr]-'a']->dep=now->dep+1;
}

void addedge(int u,int v){
    // cout<<"addedge: "<<u<<" <-> "<<v<<endl;
    G[u].push_back(v);
    G[v].push_back(u);
}

void buildAC(){
    queue<node*> q;
    root->fail=root;
    for(int i=0;i<26;++i){
        if(!root->ch[i])root->ch[i]=root;
        else root->ch[i]->fail=root,q.push(root->ch[i]);
    }
    while(q.size()){
        for(int i=0;i<26;++i){
            if(q.front()->ch[i]){
                q.front()->ch[i]->fail=q.front()->fail->ch[i];
                q.push(q.front()->ch[i]);
                if(abs(q.front()->ch[i]->dep-q.front()->fail->ch[i]->dep)==1)
                addedge(q.front()->ch[i]->id,q.front()->fail->ch[i]->id);
            }
            else q.front()->ch[i]=q.front()->fail->ch[i];
        }
        q.pop();
    }
}

void dp(int now){
    v[now]=1;
    int mx0=0,mx1=0;
    for(int i:G[now]){
        if(!v[i]){
            dp(i);
            mx0+=max(dpa[i][0],dpa[i][1]);
            mx1+=dpa[i][0];
        }
    }
    dpa[now][0]=mx0;
    dpa[now][1]=mx1+1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        for(int i=1;i<=node_id;++i)G[i].clear();
        node_id=0;
        root=new node();
        int n; cin>>n;
        while(n--){
            string s; cin>>s;
            // reverse(s.begin(),s.end());
            build(root,0,s,0);
        }
        buildAC();
        int ans=0;
        v.reset();
        for(int i=2;i<=node_id;++i){
            if(!v[i]){
                dp(i);
                ans+=max(dpa[i][0],dpa[i][1]);
            }
        }
        cout<<ans<<endl;
    }
}
