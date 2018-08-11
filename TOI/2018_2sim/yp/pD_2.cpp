#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 300006;
const LL INF = (1LL << 60) + 880301;

LL dp[N];
LL a[N];

LL pre[N];

int determine[N];

LL n;
int k;

LL cal2(int j,int i)
{
    //if (i-j + 1 < k) return INF + 880301;
    int mid = (j + i) >> 1;
    return (pre[i] - pre[mid] - (i - mid)*a[mid]) + ( a[mid]*(mid - j + 1) - (pre[mid] - pre[j-1]));
}

LL cal(int j,int i)
{
    if (i-j < k) return INF + 880301;
    return dp[j] + cal2(j+1,i);
}

struct Sagiri
{
    int l,r;
    int pos;
    Sagiri(){}
    Sagiri(int _l,int _r,int _pos) : l(_l) , r(_r) , pos(_pos){}
};

int main ()
{
    //LL n,k;
    scanf("%lld %d",&n,&k);
    dp[0] = 0;
    for (int i=1;n>=i;i++)
    {
        scanf("%lld",&a[i]);
        dp[i] = INF;
    }
    sort(a+1,a+n+1);
    deque<Sagiri> dq;
    dq.push_back(Sagiri(k,n,0));
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    for (int i=k;n>=i;i++)
    {
        int deter = dq[0].pos;
        //cout << "i = "<<i<<" , pos = "<<deter<<endl;
        dp[i] = cal(deter,i);
        //int last_R = n;
        Sagiri _ = dq.front();
        if (_.r == i)
        {
            dq.pop_front();
        }
        else
        {
            dq.pop_front();
            _.l++;
            dq.push_front(_);
        }
        while (!dq.empty())
        {
            Sagiri tmp = dq.back();
            if (cal(tmp.pos,tmp.l) > cal(i,tmp.l))
            {
                dq.pop_back();
            }
            else break;
        }
        if (dq.empty())
        {
            dq.push_back(Sagiri(i+1,n,i));
            //cout << "dq empty" << endl;
        }
        else
        {
            //binary search
            //cout << "ready bst" << endl;
            Sagiri __ = dq.back();
            int l = __.l, r = __.r;
            //cout << "i = "<<i<<" , r = "<<r<<endl;
            //cout << "pos = "<<__.pos<<" , cal pos = "<<cal(__.pos,r)<< " ,cal else = "<<cal(i,r)<<endl;
            //cout << cal(i,r) <<endl;
            if (cal(__.pos,r) <= cal(i,r))
            {
                if (r + 1 <= n)dq.push_back(Sagiri(r+1,n,i));
                continue;
            }
            //cout << "in binary search"<<endl;
            while (r-l > 1)
            {
                int mid=(l+r)>>1;
                if (cal(__.pos,mid) > cal(i,mid)) r = mid;
                else l = mid;
            }
            //cout << "final r = "<<r<<endl;
            dq.pop_back();
            __.r = r - 1;
            dq.push_back(__);
            dq.push_back(Sagiri(r,n,i));
        }
    }
    printf("%lld\n",dp[n]);
}
