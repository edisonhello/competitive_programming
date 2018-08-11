#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    Treap *lc,*rc;
    int pri,key,val;
    int mx;
    Treap(int _key,int _val):lc(NULL),rc(NULL),pri(rand()),key(_key),val(_val),mx(_val){}
};

const int INF = 0;

int Mx(Treap* t)
{
    return t?t->mx:-INF;
}

void pull(Treap* t)
{
    if (!t) return;
    t->mx = max( max( Mx(t->lc),Mx(t->rc) ) ,t->val);
}

Treap* merge(Treap* a,Treap* b)
{
    if (!a || !b) return a?a:b;
    else if (a->pri > b->pri)
    {
        a->rc=merge(a->rc,b);
        pull(a);
        return a;
    }
    else
    {
        b->lc=merge(a,b->lc);
        pull(b);
        return b;
    }
}

void split(Treap* t,int k,Treap* &a,Treap* &b)
{
    if (!t) a=b=NULL;
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

void addd(Treap* &root,int key,int val)
{
    Treap *tl,*tr;
    split(root,key-1,tl,root);
    root = merge(tl,merge(new Treap(key,val),root));
}

int Q(Treap* &root,int L,int R)
{
    Treap *tl,*tr;
    split(root,L-1,tl,root);
    split(root,R,root,tr);
    int ret = Mx(root);
    root = merge( merge(tl,root),tr );
    return ret;
}

typedef pair<int,int> pii;

int main ()
{
    Treap* root = NULL;
    Treap* dpR = NULL;
    vector<pii> v;
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int L,R;
        scanf("%d %d",&L,&R);
        v.push_back(make_pair(R,-L));
    }
    int ans = 0;
    sort(v.begin(),v.end());
    for (pii p:v)
    {
        int L = -p.second;
        int R = p.first;
        int ret = Q(root,L,R) + 1;
        //cout << "L = "<<L<<" , R = "<<R<<" , ret = "<<Q(L,R)<<endl;
        ans = max(ans,ret);
        addd(root,L,ret);
        addd(dpR,R,ret);
    }
    vector<pii> vv;
    for (pii p:v)
    {
        int L = -p.second;
        int R = p.first;
        vv.push_back(make_pair(-L,R));
        //p = make_pair(L,-R);
    }
    v = vv;
    sort(v.begin(),v.end());
    root = NULL;
    for (pii p:v)
    {
        int R = p.second;
        int L = -p.first;
        int ret = Q(root,L,R) + 1;
        //cout << "L = "<<L<<" , R = "<<R<<" , ret = "<<Q(root,L,R)<<endl;
        ans = max(ans,ret);
        ans = max(ans,ret + Q(dpR,-2000000009,L));
        addd(root,R,ret);
    }
    printf("%d\n",ans);
}
