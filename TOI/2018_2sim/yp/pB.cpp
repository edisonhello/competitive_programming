#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> v[1234567];
bool used[1234567];


bool can(int n,int p,int q)
{
    if (n < 0 || q < 0) return false;
    if (q < n) return false;
    return true;
}

int ori_q = 0;

void show(int n,int p,int q)
{
    for (int i=1;p>=i;i++)
    {
        int tmp = 0;
        for (int j=0;v[i].size()>j;j++)
        {
            if (j) printf(" ");
            printf("%d",v[i][j]);
            tmp += v[i][j];
        }
        if (tmp!=ori_q)
        {
            //puts("wrong answer");
        }
        puts("");
    }
    //puts("accepted");
}

int tot[1234567];

void count_tot(int p)
{
    for (int i=1;p>=i;i++)
    {
        for (int j:v[i]) tot[i] += j;
    }
}

const int G = 5;

void solve1(int n,int p,int q)
{
    assert(can(n,p,q));
    int id = 0;
    //cout << "n = "<<n<<" , p = "<<p<<" , q = "<<q<<endl;
    for (int i=n;i>=1;i--)
    {
        int rev = q - i;
        //assert(rev >= 0);
        //assert(rev <= n);
        //cout << "i = "<<i<<" , id = "<<id<<endl;
        //cout << "p = "<<p<<endl;
        //cout << "rev = "<<rev<<endl;
        if (rev >= i)
        {
            set<pii> st;
            for (int i=id+1;p>=i;i++)
            {
                st.insert(make_pair(q,i));
            }
            vector<int> vv;
            for(int i=n;i>=1;i--)
            {
                if (!used[i]) vv.push_back(i);
            }
            for (int ii=0;vv.size()>ii;ii++)
            {
                //if (used[i]) continue;
                //cout << "ii = "<<i<<endl;

                int sz = (int)vv.size();
                if (sz - ii <= 5) random_shuffle(vv.begin() + ii,vv.end());
                int i = vv[ii];
                //cout << "i = "<<i<<endl;
                pii _ = make_pair(i,-1);
                auto iter = st.lower_bound(_);
                if (iter == st.end())
                {
                    assert(0);
                }
                st.erase(iter);
                pii __ = *iter;
                v[__.second].push_back(i);
                //cout << "second = "<<__.second<<endl;
                //cout << "second = "<<__.second<<endl;
                __.first -= i;
                if (__.first != 0) st.insert(__);
            }
            break;
        }
        else
        {
            //cout << "i = "<<i<<" , rev = "<<rev<<endl;
            id++;
            used[i] = 1;
            used[rev] = 1;
            v[id].push_back(i);
            if (rev != 0) v[id].push_back(rev);
        }
    }
    /*
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
    */
    show(n,p,q);

}

int main ()
{
    srand(time(NULL));
    int n,p,q;
    cin >> n >> p >> q;
    ori_q = q;
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
