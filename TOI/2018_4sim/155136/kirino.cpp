#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 23;

vector<int> G[N];
int val[N];

bool hhave[N];

#define upper_bound sagiri

int dfs(int now,int par,int upper_bound)
{
    //cout << "now = " << now << " par = " << par << " , upper_bound = " << upper_bound << endl;
    if (hhave[now] && val[now] >= upper_bound && now != 1) return -1;
    int ret = hhave[now] * val[now];
    int sons = 0;
    for (int i:G[now])
    {
        if (i != par)
        {
            ++sons;
            int _ = upper_bound;
            if (hhave[now]) _ = val[now];
            int __ = dfs(i,now,_);
            if (__ == -1) return -1;
            ret += __;
        }
    }
    return ret;
}

typedef pair<int,int> pii;

struct Treap
{
    Treap *lc,*rc;
    int pri;
    pii mx;
    pii val;
    int key;
    Treap(){}
    Treap(int _key,pii _val) : lc(NULL),rc(NULL),pri(rand()),mx(_val),key(_key),val(_val){}
};

pii gee = make_pair(-123456789,-123456789);

pii Mx(Treap* t)
{
    return t?t->mx : gee;
}

void pull(Treap* t)
{
    if (!t) return;
    t->mx = max( max ( Mx(t->lc),Mx(t->rc) ) ,t->val);
}

Treap* merge(Treap* a,Treap *b)
{
    if (!a || !b) return a?a:b;
    else if (a->pri > b->pri)
    {
        a->rc = merge(a->rc,b);
        pull(a);
        return a;
    }
    else
    {
        b->lc = merge(a,b->lc);
        pull(b);
        return b;
    }
}

void split(Treap* t,int k,Treap* &a,Treap* &b)
{
    if (!t)a=b=NULL;
    else if (t->key <= k)
    {
        a=t;
        split(t->rc,k,a->rc,b);
        pull(a);
    }
    else
    {
        b=t;
        split(t->lc,k,a,b->lc);
        pull(b);
    }
}

int dp[80006];

int nxt[80006];
int last[80006];

main ()
{
    int n;
    //scanf("%d",&n);
    cin >> n;
    if (n > 20 || true)
    {
        for (int i=1;n>=i;i++)
        {
            cin >>val[i];
        }
        for (int i=2;n>=i;i++)
        {
            int x;
            cin >> x;
            nxt[x]= i;
        }
        vector<int> v;
        int now=1;
        for (int i=1;n>=i;i++)
        {
            v.push_back(now);
            now = nxt[now];
        }
        dp[1] = val[1];
        Treap* root=NULL;
        root = merge(root,new Treap(val[1],make_pair(dp[1],1)));
        for (int ii=1;n>ii;ii++)
        {
            int i = v[ii];
            Treap *tl;
            split(root,val[i],tl,root);
            pii _ = Mx(tl);
            root = merge(tl,root);
            cout << "i = " <<i << " , _ = " << _.first <<endl;
            if (_ != gee)
            {
                dp[i] = dp[_.second] + val[i];
                last[i] = _.second;
                Treap *tl;
                split(root,val[i],tl,root);
                root = merge(merge(tl,new Treap(val[i],make_pair(dp[i],i))) , root);
            }
        }
        int ans_mx = -1;
        int mx_id = -1;
        for (int i=1;n>=i;i++)
        {
            if (dp[i] > ans_mx)
            {
                ans_mx = dp[i];
                mx_id = i;
            }
        }
        v.clear();
        //vector<int> v;
        while (mx_id != 1)
        {
            v.push_back(mx_id);
            mx_id = last[mx_id];
        }
        sort(v.begin(),v.end());
        cout << ans_mx << endl;
        cout <<1;
        for (int i=1;v.size()>i;i++)
        {
            cout << ' ' << v[i];
        }
        cout <<endl;
        return 0;
    }
    //assert(n <= 20);
    for (int i=1;n>=i;i++)
    {
        cin >> val[i];
        //scanf("%d",&val[i]);
    }
    for (int i=2;n>=i;i++)
    {
        int x;
        cin >> x;
        //scanf("%d",&x);
        G[x].push_back(i);
        G[i].push_back(x);
    }
    int ans = -1;
    int ans_mask = -1;
    for (int mask=0;(1<<n)>mask;mask++)
    {
        //mask = 4025;
        memset(hhave,0,sizeof(hhave));
        for (int j=0;n>j;j++)
        {
            if (((1<<j)&mask) != 0)
            {
                hhave[j+1] = true;
            }
        }
        //assert(hhave[1]);
        int gee = dfs(1,1,val[1]);
        //cout << "mask = " << mask << " , ans = " << gee << endl;
        if (gee != -1)
        {
            if (gee > ans)
            {
                ans = gee;
                ans_mask = mask;
            }
        }
        //break;
    }
    //assert(ans != -1);
    cout << ans << endl;
    //printf("%d\n",ans);
    //printf("1");
    cout << 1;
    for (int i=1;n>i;i++)
    {
        if (((1<<i)&ans_mask) != 0)
        {
            cout << ' ' << i+1;
            //printf(" %d",i+1);
        }
    }
    cout << endl;
    //puts("");
}
