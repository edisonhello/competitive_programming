/*THIS IS MY CODE*//*
#include<bits/stdc++.h>
using namespace std;
int n,cnt[50],line[50][50];

void dfs(int n){
    for(int i=0;i<50;i++){
        if(line[n][i]){
            line[n][i]--;
            line[i][n]--;
            dfs(i);
            printf("%d %d\n",i+1,n+1);
        }
    }
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);


    int t;scanf("%d",&t);

    for(int i=1;i<=t;i++){
        if(i-1)printf("\n");
        printf("Case #%d\n",i);
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        memset(line,0,sizeof(line));
;       for(int j=0;j<n;j++){
            int ini,inj;
            scanf("%d%d",&ini,&inj);
            cnt[ini-1]++;
            cnt[inj-1]++;
            line[ini-1][inj-1]++;
            line[inj-1][ini-1]++;
        }
        bool fn2=false;
        for(int i=0;i<50;i++){
            if(cnt[i]&1){
                fn2=true;
                break;
            }
        }
        if(fn2){
            printf("some beads may be lost\n");
        }
        else{
            for(int i=0;i<50;i++){
                if(cnt[i]){
                    dfs(i);
                }
            }
        }
    }
}

*//*THIS IS NOT MY CODE*/


#include <stdio.h>
#include <string.h>
#define N 55
#define MAX 1010
int g[N][N],vis[N];
int d[N];
int n;


void euler(int u)
{
    int v;
    for(v=1; v<=50; v++)
        if(g[u][v])
        {
            g[u][v]--;
            g[v][u]--;
            euler(v);
            printf("%d %d\n",v,u);
        }
}
int main()
{
    int t,T;
    int i,j;
    int u,v;
    //int count,max,start;
    scanf("%d",&T);
    for(t=1 ;t<=T; t++)
    {
        memset(g,0,sizeof(g));
        //memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(i=1 ;i<=n; i++)
        {
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
            g[u][v]++;
            g[v][u]++;
        }
        printf("Case #%d\n",t);

        for(i=1 ;i<=50; i++)
            if( d[i]%2 )
                break;
        if(i<=50)
            printf("some beads may be lost\n");
        else
            for(i=1; i<=50; i++)
                euler(i);

        if(t!=T) printf("\n");
    }
    return 0;
}
