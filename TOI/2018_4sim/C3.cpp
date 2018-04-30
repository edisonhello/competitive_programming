#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000006];
bitset<1000006> is_loop,is_end;
int deg[1000006],connect_to[1000006],side_len[1000006],loop_to[1000006],count_side,loop_size;
vector<int> connecting[1000006];

struct node{
    node *l,*r;
    int val,pri,sz,mx,tag;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void pull(){sz=lz()+rz()+1; mx=max(val,max(l?l->mx:0,r?r->mx:0));}
    void push(){
        if(l)l->val+=tag,l->mx+=tag,l->tag+=tag;
        if(r)r->val+=tag,r->mx+=tag,r->tag+=tag;
        tag=0;
    }
    void addtag(int t){
        mx+=t; tag+=t; val+=t;
    }
    node(int v=0):l(0),r(0),val(v),sz(1),mx(v),pri(rand()),tag(0){}
    void set(int v){val=mx=v;}
} *add2,*add1,*add0,pool[4000009];
int __ptr=-1;

inline node *gnode(int v){
    // return new node(v);
    ++__ptr;
    node *rt=&pool[__ptr];
    rt->set(v);
    return rt;
}

int _dfs1_len=0;
int dfs1(int now,int pa){
    if(is_loop[now])return now;
    for(int i:G[now]){
        if(i==pa)continue;
        ++_dfs1_len;
        return dfs1(i,now);
    }
}

int loop_start;
void dfs2(int now,int pa){
//    cout<<"now: "<<now<<endl;
    if(now==loop_start && now!=pa)return;
    ++loop_size;
    for(int i:G[now]){
        if(i==pa)continue;
        if(!is_loop[i])continue;
        loop_to[now]=i;
        dfs2(i,now);
        return;
    }
}

int dp[4][1000006];
void dfs3(int now,int pa,int lid){
    connect_to[now]=lid;
    dp[1][now]=dp[2][now]=G[now].size();
    if(G[now].size()==1)return;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs3(i,now,lid);
    }
    for(int i:G[now])if(i!=pa){
        dp[1][now]=max(dp[1][now],(int)G[now].size()-1+dp[1][i]);
    }
    dp[2][now]=dp[1][now];
    vector<int> vals;
    for(int i:G[now])if(i!=pa){
        vals.push_back(dp[1][i]);
    }
    sort(vals.begin(),vals.end(),greater<int>());
    while(vals.size()<2u)vals.push_back(0);
    dp[2][now]=max(dp[2][now],(int)G[now].size()-2+vals[0]+vals[1]);
}

int main(){
//    freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,a,b;i<=n;++i){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    { // get loop
        is_loop.set();
        queue<int> q;
        for(int i=1;i<=n;++i){
            if(deg[i]==1)q.push(i),is_loop[i]=0,is_end[i]=1;
        }
        while(q.size()){
            int now=q.front(); q.pop();
            for(int i:G[now]){
                if(!is_loop[i])continue;
                --deg[i];
                if(deg[i]==1 && is_loop[i]){
                    is_loop[i]=0;
                    q.push(i);
                }
            }
        }
//        for(int i=1;i<=n;++i)if(is_loop[i])cout<<i<<" is loop"<<endl;
    }
    { // order loop
        for(int i=1;i<=n;++i)if(is_loop[i]){loop_start=i; break;}
        dfs2(loop_start,loop_start);
    }
    int ans=3;
    {
        for(int i=1;i<=n;++i){
            if(!is_loop[i])continue;
            for(int j:G[i]){
                if(is_loop[j])continue;
                dfs3(j,i,i);
            }
        }
        for(int i=1;i<=n;++i)if(!is_loop[i])ans=max(ans,dp[2][i]+1);
//         for(int i=1;i<=n;++i)cout<<"dp of "<<i<<" : "<<dp[1][i]<<" "<<dp[2][i]<<endl;
    }
    for(int i=1;i<=n;++i)if(is_loop[i])count_side+=G[i].size()-2;
    {
        ans=max(ans,loop_size+count_side);
        int st_point=0;
        for(int i=1;i<=n;++i)if(is_loop[i]){st_point=i; break;}
        for(int u=st_point,v2=0;;u=loop_to[u]){
            if(u==st_point)++v2;
            if(v2>=2)break;
            for(int i:G[u]){
                if(is_loop[i])continue;
                ans=max(ans,loop_size+dp[1][i]+count_side-1);
            }
        }
    }

    function<node*(node*,node*)> merge=[&](node *a,node *b){
        if(!a)return b;
        if(!b)return a;
        a->push(); b->push();
        if(a->pri>b->pri)return a->r=merge(a->r,b),a->pull(),a;
        else return b->l=merge(a,b->l),b->pull(),b;
    };
    function<void(node*,int,node*&,node*&)> split=[&](node *now,int sz,node *&a,node *&b){
        // cout<<"splitting "<<now<<" with neeed size "<<sz<<endl;
        if(!now){a=b=0; return;}
        now->push();
        // cout<<"after push"<<endl;
        if(now->lz()>=sz){
            b=now;
            split(now->l,sz,a,b->l);
            b->pull();
        }
        else{
            a=now;
            split(now->r,sz-1-now->lz(),a->r,b);
            a->pull();
        }
    };
    function<void(node*)> ptree=[&](node *now){
        if(!now)return;
        if(now->l)cout<<"(",ptree(now->l),cout<<")";
        cout<<now->val<<","<<now->tag;
        if(now->r)cout<<"(",ptree(now->r),cout<<")";
    };
    {
        int st_point=0;
        for(int i=1;i<=n;++i)if(is_loop[i]){st_point=i; break;}
        int near=0,looplen=0;
        for(int u=st_point,v2=0;;u=loop_to[u]){
            if(u==st_point)++v2; if(v2>=2)break;
            near+=G[u].size()-2;
            ++looplen;
            if(loop_to[u]==st_point){
                for(int i:G[u]){
                    if(is_loop[i])continue;
                    add0=merge(add0,gnode(dp[1][i]+near-2+looplen));
                }
            }
            else if(loop_to[loop_to[u]]==st_point){
                for(int i:G[u]){
                    if(is_loop[i])continue;
                    add1=merge(add1,gnode(dp[1][i]+near+1-2+looplen));
                }
            }
            else{
                for(int i:G[u]){
                    if(is_loop[i])continue;
//                    cout<<"for "<<i<<" add "<<dp[1][i]+near+looplen<<endl;
                    add2=merge(add2,gnode(dp[1][i]+near+2-2+looplen));
                }
            }
        }
//        cout<<"inited "<<" "<<add0<<" "<<add1<<" "<<add2<<endl;
        for(int u=st_point,v2=0;;u=loop_to[u]){
//            cout<<"now u: "<<u<<endl;
//            cout<<"p add2: "; ptree(add2); cout<<endl;
//            cout<<"p add1: "; ptree(add1); cout<<endl;
//            cout<<"p add0: "; ptree(add0); cout<<endl;
            if(u==st_point)++v2; if(v2>=2)break;
            for(int i:G[u]){
                if(is_loop[i])continue;
//                cout<<"chain i: "<<i<<endl;
                node *trash,*tmp;
                split(add2,1,trash,tmp); add2=tmp;
//                cout<<"p add2: "; ptree(add2); cout<<endl;
                int my_len=dp[1][i];
//                cout<<"my_len: "<<my_len<<endl;
//                cout<<"update ans with "<<my_len+(add2?add2->mx:0)<<endl;
//                cout<<"update ans with "<<my_len+(add1?add1->mx:0)<<endl;
//                cout<<"update ans with "<<my_len+(add0?add0->mx:0)<<endl;
                ans=max(ans,my_len+(add2?add2->mx:0));
                ans=max(ans,my_len+(add1?add1->mx:0));
                ans=max(ans,my_len+(add0?add0->mx:0));
            }
            while(add1){
                // cout<<"moving 1 to 2"<<endl;
                node *a,*b;
                // cout<<"before split"<<endl;
                split(add1,1,a,b);
                // cout<<"after"<<endl;
                add1=b;
                add2=merge(add2,gnode(a->val+1));
//                delete a;
            }
            while(add0){
                // cout<<"moving 0 to 1"<<endl;
                node *a,*b;
                split(add0,1,a,b);
                add0=b;
                add1=merge(add1,gnode(a->val+1));
//                delete a;
            }
            if(add2)add2->addtag(-(G[u].size()-2)-1);
            if(add1)add1->addtag(-(G[u].size()-2)-1);
            for(int i:G[u]){
                if(is_loop[i])continue;
                add0=merge(add0,gnode(dp[1][i]+near-2+loop_size));
            }
        }
    }
    cout<<ans<<endl;
}


