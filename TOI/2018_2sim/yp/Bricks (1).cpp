#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> v[1234567];

void solve1(int n,int p,int q)
{
    set<pii> st;
    for (int i=1;p>=i;i++)
    {
        st.insert(make_pair(q,i));
    }
    for (int i=n;i>=1;i--)
    {
        pii _ = make_pair(i,-1);
        auto iter = st.lower_bound(_);
        assert(iter != st.end());
        st.erase(iter);
        pii __ = *iter;
        v[__.second].push_back(i);
        __.first -= i;
        if (__.first != 0) st.insert(__);
    }
    for (int i=1;p>=i;i++)
    {
        for (int j=0;v[i].size()>j;j++)
        {
            if (j) printf(" ");
            printf("%d",v[i][j]);
        }
        puts("");
    }
}

void show(int n,int p,int q)
{
    for (int i=1;p>=i;i++)
    {
        for (int j=0;v[i].size()>j;j++)
        {
            if (j) printf(" ");
            printf("%d",v[i][j]);
        }
        puts("");
    }
}

bool can(int n,int p,int q)
{
    if (n < 0) return false;
    if (q < n) return false;
    return true;
}

int main ()
{
    int n,p,q;
    cin >> n >> p >> q;
    if (q < n)
    {
        puts("-1");
        return 0;
    }
    while(n != 0)
    {
        //cout << "n = "<<n<<" , p = "<<p<<" , q = "<<q<<endl;
        int yee = n - p;
        if (can(n - 2*p,p,q-yee - yee -1))
        {
            int gee1 = n;
            int gee2 = n - 2*p + 1;
            for (int i=1;p>=i;i++)
            {
                v[i].push_back(gee1);
                v[i].push_back(gee2);
                gee1--;
                gee2++;
            }
        }
        else break;
        //else break;
        q = q - yee - yee - 1;
        n -= 2*p;
    }
    if (n != 0)solve1(n,p,q);
    else show(n,p,q);
}
