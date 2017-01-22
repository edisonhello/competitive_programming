#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> G[10005];
int tm[10005];

int dfs(int &now,int &dis){
    if(now==dis)return 1;
    if(~tm[now])return tm[now];
    tm[now]=0;
    for(auto &i:G[now]){
        tm[now]+=dfs(i,dis);
    }
    return tm[now];
}

int main(){
    int n,m,a,b,v,d;scanf("%d%d",&n,&m);
    do{
        scanf("%d%d",&a,&b);
        G[b].push_back(a);
    }while(--m);
    scanf("%d%d",&v,&d);
    memset(tm,0xff,sizeof(tm));
    printf("%d\n",(dfs(d,v)&((1<<30)-1)));
}
