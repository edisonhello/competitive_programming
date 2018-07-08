#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 56;

string s[N];

int cnt[N];

int main ()
{
    int T;
    scanf("%d",&T);
    int cases=0;
    while (T--)
    {
        LL n,k,v;
        scanf("%lld %lld %lld",&n,&k,&v);
        for (int i=1;n>=i;i++)
        {
            cin >> s[i];
        }
        v = ((v-1)%n) + 1;
        LL vvv=v;
        memset(cnt,0,sizeof(cnt));
        v *= k;
        int now = 1;
        vector<int> vv;
        for (int i=1;v>=i;i++)
        {
            cnt[now]++;
            if (i > (vvv-1)*k) vv.push_back(now);
            now++;
            if (now == n+1) now = 1;
        }
        sort(vv.begin(),vv.end());
        printf("Case #%d:",++cases);
        for (int i:vv) cout << " " << s[i];
        cout << endl;
    }
}
