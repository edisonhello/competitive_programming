#include <bits/stdc++.h>
using namespace std;

typedef long long Kirino;
typedef pair<Kirino,Kirino> pii;
typedef pair<Kirino,pii> piii;

#define F first
#define S second

const int N = 202;
const int K = 19002;
const int S = 16000;
const Kirino GEE = (1LL<<60);

Kirino sagiri[N][N];
int _[N];
int deg[N];

Kirino lawfung[N][N];

Kirino meruru[K][N];

vector<int> GG[N];

vector<int> G[N];

int order[N];

Kirino dp[1000006][11];

int main ()
{
    int n,m,s,t,k;
    scanf("%d %d %d %d %d",&n,&m,&s,&t,&k);
    for (int i=0;N>i;i++)
    {
        for (int j=0;N>j;j++)
        {
            sagiri[i][j] = GEE;
            if (i==j) sagiri[i][j] = 0;
        }
    }
    for (int i=1;m>=i;i++)
    {
        int u,v,t;
        scanf("%d %d %d",&u,&v,&t);
        sagiri[u][v] = sagiri[v][u] = t;
        lawfung[u][v] = lawfung[v][u] = t;
        GG[u].push_back(v);
        GG[v].push_back(u);
    }
    for (int k=1;n>=k;k++)
    {
        for (int i=1;n>=i;i++)
        {
            for (int j=1;n>=j;j++)
            {
                sagiri[i][j] = min(sagiri[i][j],sagiri[i][k] + sagiri[k][j]);
            }
        }
    }
    if (!k)
    {
        printf("%lld\n",sagiri[s][t]);
        return 0;
    }
    for (int i=1;n>=i;i++)
    {
        if (i == t)
        {
            _[i] = -1;
        }
        else
        {
            for (int j=1;n>=j;j++)
            {
                if (j==i) continue;
                if (!lawfung[i][j]) continue;
                //cout << "i = " << i << " , j = " << j << endl;
                //cout << "lawfung = " << lawfung[i][j] << " , sagiri = " << sagiri[j][t] << " , sagiri = " << sagiri[i][t] << endl;
                if (lawfung[i][j] + sagiri[j][t] == sagiri[i][t])
                {
                    _[i] = j;
                    deg[j]++;
                    G[i].push_back(j);
                    break;
                }
            }
        }
        //cout << "i = " << i << " , _ = " << _[i] << endl;
    }
    int id=0;
    queue<int> que;
    for (int i=1;n>=i;i++)
    {
        if (deg[i] == 0) que.push(i);
    }
    while (!que.empty())
    {
        int t=que.front();
        que.pop();
        order[++id] = t;
        for (int i:G[t])
        {
            deg[i]--;
            if (!deg[i]) que.push(i);
        }
    }
    //assert(n <= 10 && m <= 55 && k <= 1000000);
    if (n <= 10 && k <= 1000000)
    {
        /*if (n == 2 || s==t || 25000000<=(8*n*k) && (8*n*k) <= 38000000 && k <= 700000)
        {
            printf("%lld\n",sagiri[s][t]);
            return 0;
        }*/
        for (int i=0;k+1>=i;i++)
        {
            for (int j=0;n>=j;j++)
            {
                dp[i][j] = -GEE;
            }
        }
        dp[0][s] = 0;
        for (int i=0;k>=i;i++)
        {
            for (int jj=1;n>jj;jj++)
            {
                int j = order[jj];
                dp[i][ _[j] ] = max(dp[i][ _[j] ],dp[i][j] + lawfung[j][ _[j] ] );
                for (int gee:GG[j])
                {
                    if (gee == _[j]) continue;
                    dp[(i+1)][ gee ] = max(dp[(i+1)][gee],dp[i][j] + lawfung[j][gee]);
                }
            }
        }
        printf("%lld\n",max(dp[k][t],sagiri[s][t]));
        return 0;
    }

    for (int i=0;K>i;i++)
    {
        for (int j=0;N>j;j++)
        {
            meruru[i][j] = -GEE;
        }
    }
    meruru[0][s] = 0;
    //for (int i=1;n>=i;i++) cout << order[i] << ' ';
    int realk = k;
    k = min(k,K-2);
    for (int i=0;K>i;i++)
    {
        for (int jj=1;n>jj;jj++)
        {
            int j = order[jj];
            meruru[i][ _[j] ] = max(meruru[i][ _[j] ],meruru[i][j] + lawfung[j][ _[j] ] );
            for (int gee:GG[j])
            {
                if (gee == _[j]) continue;
                meruru[i+1][ gee ] = max(meruru[i+1][gee],meruru[i][j] + lawfung[j][gee]);
            }
        }
    }
    if (k == realk) printf("%lld\n",meruru[k][t]);
    else
    {
        //cout << "inn" << endl;
        k = realk;
        int start = S;
        vector<Kirino> vv;
        set<Kirino> st;
        int last = -1;
        Kirino tot=0;
        const int MM = 2997;
        for (int i=start;start+MM>i;i++)
        {
            Kirino _ = meruru[i+1][t] - meruru[i][t];
            vv.push_back(_);
            tot += _;
            //cout << _ << " ";
        }
        //cout << "finshing _" << endl;
        //find the min len
        Kirino len;
        for (len=1;;len++)
        {
            //checking
            bool can=true;
            for (int i=0;vv.size()>i;i++)
            {
                if (vv[i] == vv[i%len]) ;
                else
                {
                    can=false;
                    break;
                }
            }
            if (can)
            {
                tot=0;
                for (int i=0;len>i;i++) tot += vv[i];
                break;
            }
        }
        //cout << "last = " << last << endl;
        //Kirino len = last - start;
        //cout << "len = " << len << endl;
        Kirino tmp = k - start;
        Kirino ans = meruru[start][t];
        ans += (tmp/len) * tot;
        tmp %= len;
        //cout << "tmp = " <<tmp << " , vv.size() = " << vv.size() << endl;
        for (int i=0;tmp>i;i++) ans += vv[i];
        printf("%lld\n",max(ans,sagiri[s][t]));
        return 0;
        //printf("%lld\n",meruru[k][t] + (meruru[k][t] - meruru[k-1][t]) * (realk - k));
    }
}

/*
6 6 3 4 1
1 2 10
2 3 10
3 4 10
5 4 20
6 5 10
1 6 10
*/
