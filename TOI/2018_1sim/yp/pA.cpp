#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <set>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 100060;

int c[N];

int p,k,n;
vector<int> v;

void show_ans(vector< vector<pii> > ans)
{
    for (vector<pii> v:ans)
    {
        //printf("%d",(int)v.size());
        vector<int> anss;
        for (pii p:v)
        {
            anss.push_back(p.first);
            anss.push_back(p.second);
        }
        for (int i=0;anss.size()>i;i++)
        {
            if (i) printf(" ");
            printf("%d",anss[i]);
        }
        puts("");
    }
    exit(0);
}

void dfs(int now,vector<int> items,vector<vector<pii> > ans)
{
    if (now == k)
    {
        show_ans(ans);
        exit(0);
    }
    //vector< vector<pii> > cans;
    for (int i=0;p>i;i++)
    {
        for (int j=i+1;p>j;j++)
        {
            if (items[i] + items[j] >= n && items[i] > 0 && items[j] > 0)
            {
                /*
                if (n > items[j])
                {
                    int x = items[j];
                    items[j] -= x;
                    items[i] -= (n-x);
                    vector<vector<pii> > pp = ans;
                    vector<pii> aa;
                    aa.push_back(make_pair(i+1,(n-x)));
                    aa.push_back(make_pair(j+1,x));
                    pp.push_back(aa);
                    dfs(now+1,items,pp);
                    items[j] += x;
                    items[i] += (n-x);
                }
                if (n > items[i])
                {
                    swap(i,j);
                    int x = items[j];
                    items[j] -= x;
                    items[i] -= (n-x);
                    vector<vector<pii> > pp = ans;
                    vector<pii> aa;
                    aa.push_back(make_pair(i+1,(n-x)));
                    aa.push_back(make_pair(j+1,x));
                    pp.push_back(aa);
                    dfs(now+1,items,pp);
                    items[j] += x;
                    items[i] += (n-x);
                    swap(i,j);
                }
                */
                int xx = rand() % (min(min(items[i],items[j]),n)) + 1;
                int x = xx;
                //while (items[i] < x || items[j] )
                bool swapp = false;
                if (items[j] > items[i]) swapp = true;
                if (swapp) swap(i,j);
                //cout << "items j = "<<items[j]<<" , items i = "<<items[i]<<" , x  = "<<x<<endl;
                items[j] -= x;
                items[i] -= (n-x);
                vector<vector<pii> > pp = ans;
                vector<pii> aa;
                aa.push_back(make_pair(i+1,(n-x)));
                aa.push_back(make_pair(j+1,x));
                pp.push_back(aa);
                dfs(now+1,items,pp);
                items[j] += x;
                items[i] += (n-x);
                if (swapp) swap(i,j);
            }
        }
    }
    for (int i=0;p>i;i++)
    {
        if (items[i] >= n)
        {
            items[i] -= n;
            vector<vector<pii> > pp = ans;
            vector<pii> aa;
            aa.push_back(make_pair(i+1,n));
            pp.push_back(aa);
            dfs(now+1,items,pp);
            items[i] += n;
        }
    }
}

int main ()
{
	//int p,k,n;
	clock();
	scanf("%d %d %d",&p,&k,&n);
	if (p != k+2)
    {
        //priority_queue<pii> pq;
        set<pii> st;
        for (int i=1;p>=i;i++)
        {
            scanf("%d",&c[i]);
            st.insert(make_pair(c[i],i));
        }
        vector< vector<pii> > ans;
        while (!st.empty())
        {
            pii p=*st.begin();
            st.erase(st.begin());
            //cout << "p = "<<p.first<<" , "<<p.second<<endl;
            if (p.first >= n)
            {
                vector<pii> vv;
                vv.push_back(make_pair(p.second,n));
                p.first -= n;
                if (p.first != 0)st.insert(p);
                ans.push_back(vv);
            }
            else
            {
                if (st.empty())
                {
                    puts("-1");
                    return 0;
                }
                pii pp = *(--st.end());
                st.erase((--st.end()));
                int need = n - p.first;
                if (pp.first >= need)
                {
                    vector<pii> vv;
                    vv.push_back(make_pair(p.second,p.first));
                    vv.push_back(make_pair(pp.second,need));
                    pp.first -= need;
                    if (pp.first != 0)st.insert(pp);
                    ans.push_back(vv);
                }
                else
                {
                    puts("-1");
                    return 0;
                }
            }
        }
        for (vector<pii> v:ans)
        {
            //printf("%d",(int)v.size());
            vector<int> anss;
            for (pii p:v)
            {
                anss.push_back(p.first);
                anss.push_back(p.second);
            }
            for (int i=0;anss.size()>i;i++)
            {
                if (i) printf(" ");
                printf("%d",anss[i]);
            }
            puts("");
        }
        return 0;
    }
    vector<int> v;
    for (int i=0;p>i;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    vector< vector<pii> > ans;
    dfs(0,v,ans);
    puts("-1");
}
