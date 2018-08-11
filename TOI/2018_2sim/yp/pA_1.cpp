#include <bits/stdc++.h>
using namespace std;

const int N = 5006;
const int NN = 19;
const int INF = 0x3f3f3f3f;

int cost[N][N];
int dp[(1<<NN)][NN];

int lc[N];
int rc[N];

int main ()
{
    int n,m1,m2;
    scanf("%d %d %d",&n,&m1,&m2);
    for (int q=1;m1>=q;q++)
    {
        int ii,jj,kk;
        scanf("%d %d %d",&ii,&jj,&kk);
        for (int i=0;ii>=i;i++)
        {
            for (int j=jj;n>j;j++)
            {
                cost[i][j] += kk;
            }
        }
    }
    for (int q=1;m2>=q;q++)
    {
        int ii,jj,kk;
        scanf("%d %d %d",&ii,&jj,&kk);
        for (int i=ii;n>i;i++)
        {
            for (int j=0;jj>=j;j++)
            {
                cost[i][j] += kk;
            }
        }
    }
    int __ = INF;
    for (int ed=1;n-1>=ed;ed++)
    {
        rc[0] = ed;
        int ans = cost[0][n-1] + cost[n-1][0];
        for (int i=1;n>i;i++)
        {
            if (i == ed) continue;
            int now = 0;
            int delta_mn = INF;
            int now_id = -1;
            //cout << "i = "<<i<<endl;
            for (;now != ed; now = rc[now])
            {
                //cout << "now = "<<now<<endl;
                int _ = cost[now][i] + cost[i][ rc[now] ] - cost[now][ rc[now] ];
                if (_ < delta_mn)
                {
                    delta_mn = _;
                    now_id = now;
                }
            }
            ans += delta_mn;
            now = 0;
            for (;now != ed;now = rc[now])
            {
                if (now == now_id)
                {
                    //rc[now] = i;
                    rc[i] = rc[now];
                    rc[now] = i;
                    break;
                }
            }
        }
        __ = min(__,ans);
    }
    printf("%d\n",__);
}
