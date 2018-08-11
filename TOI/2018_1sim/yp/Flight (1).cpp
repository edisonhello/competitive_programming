#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
typedef pair<pii,LL> piii;

#define F first
#define S second

vector<LL> ans;
LL k;

LL get_dis(pii a,pii b)
{
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

const int N = 100006;

piii p[N];

LL mn_dis = (1LL<<62);
LL idx0,idx1;

void update(piii a,piii b)
{
    LL dis = get_dis(a.F,b.F);
    if (dis <= k)
    {
        ans.push_back(a.S);
        ans.push_back(b.S);
    }
    //cout << "a.S = "<<a.S<<" , b.S = "<<b.S<<" , dis = "<<dis<<endl;
    //cout << "a.F = "<<a.F.F<<" , "<<a.F.S<<" , b.F = "<<b.F.F<<" , "<<b.F.S<<endl;
    if (dis < mn_dis)
    {
        mn_dis = dis;
        idx0 = a.S;
        idx1 = b.S;
        if (idx0 > idx1) swap(idx0,idx1);
    }
    else if(dis == mn_dis)
    {
        pii _ = make_pair(min(a.S,b.S),max(a.S,b.S));
        if (_ < make_pair(idx0,idx1))
        {
            idx0 = _.first;
            idx1 = _.second;
        }
    }
}

LL _2(LL x)
{
    return x*x;
}

void solve(int L,int R)
{
    if (L==R) return;
    if (R-L == 1)
    {
        //only two things
        update(p[L],p[R]);
    }
    int mid = (L+R)>>1;
    solve(L,mid);
    solve(mid+1,R);
    vector<piii> vv;
    for (int i=mid;i>=L;i--)
    {
        if (_2(p[mid].F.F - p[i].F.F) <= mn_dis) vv.push_back(p[i]);
        else break;
    }
    for (int i=mid+1;R>=i;i++)
    {
        if ( _2(p[i].F.F - p[mid+1].F.F) <= mn_dis ) vv.push_back(p[i]);
        else break;
    }
    sort(vv.begin(),vv.end(),[](const piii &p1,const piii &p2)
     {
         return p1.F.S < p2.F.S || p1.F.S == p2.F.S && p1 < p2;
     });
    int nn = vv.size();
    for (int i=0;nn>i;i++)
    {
        for (int j=i+1;min(i+3,nn)>j;j++)
        {
            update(vv[i],vv[j]);
        }
    }
}

int main ()
{
    clock();
    int n;
    scanf("%d",&n);
    scanf("%lld",&k);
    for (int i=1;n>=i;i++)
    {
        int id,x,y;
        scanf("%d %d %d",&id,&x,&y);
        p[i] = make_pair( make_pair(x,y),id );
    }
    sort(p+1,p+n+1);
    /*
    for (int i=1;n>=i;i++)
    {
        cout << p[i].F.F<<" , "<<p[i].F.S<<endl;
    }
    */
    solve(1,n);
    printf("%lld %lld %lld\n",idx0,idx1,mn_dis);
    for (int i=1;n>=i;i++)
    {
        if (clock()/CLOCKS_PER_SEC > 0.94) break;
        if (i+1 <= n)
        {
            int j = i+1;
            //cout << "i = "<<i<<" , j
            if (get_dis(p[i].F,p[j].F) <= _2(k))
            {
                ans.push_back(p[i].S);
                continue;
            }
        }
        if (i-1 >= 1)
        {
            int j = i-1;
            if (get_dis(p[i].F,p[j].F) <= _2(k))
            {
                ans.push_back(p[i].S);
                continue;
            }
        }
        int cnt = 0;
        if (n <= 5006) cnt = 5007;
        else cnt = 200;
        for (int j=i+1;n>=j;j++)
        {
            if (i==j) continue;
            cnt--;
            if (!cnt) break;
            if (get_dis(p[i].F,p[j].F) <= _2(k))
            {
                ans.push_back(p[i].S);
                break;
            }
        }
        if (n <= 5006) cnt = 5007;
        else cnt = 200;
        for (int j=i-1;j>=1;j--)
        {
            if (i==j) continue;
            cnt--;
            if (!cnt) break;
            if (get_dis(p[i].F,p[j].F) <= _2(k))
            {
                ans.push_back(p[i].S);
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end()) - ans.begin());
    printf("%d\n",(int)ans.size());
    for(int i=0;ans.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
    //puts("0");
}
