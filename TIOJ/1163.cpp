#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue

inline int rit(){
    int t=0;
    char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t;
}

int v,e;
int x,y,d;
vector<pii> G[30005];
int q;
int st,ed;
bitset<30005> gone;
int i;
int res;
int ans;
bitset<30005> tried;

int dfs(int now,int t){
    // cout<<"dfs now="<<now<<", t="<<t<<endl;
    if(now==ed){
        if(ans==-1) ans=t;
        else{
            ans=min(ans,t);
            return 0;
        }
    }
    if((int)G[now].size()==0) return -1;
    tried.reset();
    for(int j=0;j<(int)G[now].size();j++){
        if(gone[G[now][j].X] || tried[G[now][j].X]) continue;
        gone[G[now][j].X]=1;
        tried[G[now][j].X]=1;
        res=dfs(G[now][j].X,max(t,G[now][j].Y));
        if(res==-1) return -1;
        gone[G[now][j].X]=0;
    }
    return 0;
}

int main(){
    v=rit(),e=rit();
    for(i=0;i<e;i++){
        x=rit(),y=rit(),d=rit();
        if(x==y) continue;
        G[x].push_back({y,d});
        G[y].push_back({x,d});
    }
    q=rit();
    for(i=0;i<q;i++){
        gone.reset();
        ans=-1;
        st=rit(),ed=rit();
        if(st==ed){
            putchar('0');
            putchar('\n');
            continue;
        }
        if(dfs(st,0)==-1){
            putchar('-');
            putchar('1');
            putchar('\n');
        }
        printf("%d\n",ans);
    }
}
