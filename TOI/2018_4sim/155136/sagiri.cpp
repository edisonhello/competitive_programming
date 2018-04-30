#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];

bool vis[N];

int ans=0;

int meruru;

int n;

void dfs(int now)
{
    if (now == meruru)
    {
        int tmp_ans = 0;
        for (int i=1;n>=i;i++)
        {
            if (vis[i]) tmp_ans++;
            else
            {
                for(int j:G[i])
                {
                    if (vis[j])
                    {
                        tmp_ans++;
                        break;
                    }
                }
            }
        }
        ans = max(ans,tmp_ans);
        return;
    }
    for (int i:G[now])
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(i);
            vis[i] = false;
        }
    }
}

void update(int s,int t)
{
    meruru = t;
    memset(vis,0,sizeof(vis));
    vis[s] = true;
    dfs(s);
}

int main ()
{
    clock();
    srand(time(NULL));
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    while ((double)clock()/CLOCKS_PER_SEC < 0.98)
    {
        int l=rand()%n+1, r = rand()%n+1;
        while (l==r)
        {
            l = rand()%n+1;
            r = rand()%n+1;
        }
        update(l,r);
    }
    /*
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            if (i==j) continue;
            update(i,j);
        }
    }
    */
    printf("%d\n",ans);
}
