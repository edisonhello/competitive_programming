#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    Treap *lc,*rc;
    int pri,key,ans;
    int mx,mn;
    Treap(int _key,int _pri):lc(NULL),rc(NULL),pri(_pri),key(_key),ans(1),mx(_key),mn(_key){}
};

bool Have(Treap* t)
{
    return t?true:false;
}

int Ans(Treap* t)
{
    return t?t->ans:0;
}

const int INF = 1000000007;

int Mx(Treap* t)
{
    return t?t->mx:-INF;
}

int Mn(Treap* t)
{
    return t?t->mn:INF;
}

void pull(Treap* t)
{
    if (true) return;
    if (!Have(t->lc) && !Have(t->rc))
    {
        t->ans = 1;
        return;
    }
    else
    {
        t->ans = Ans(t->lc) + Ans(t->rc);
    }
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

Treap* root;

vector<int> v;

int dfs(Treap* root)
{
    if (!root) return 0;
    v.push_back(root->key);
    int ret = dfs(root->lc);
    ret += dfs(root->rc);
    if (root->lc == NULL && root->rc == NULL) ++ret;
    return ret;
}

int cnt_ans()
{
    return dfs(root);
}

void addd(int k,int pri)
{
    Treap *tl,*tr;
    split(root,k-1,tl,root);
    root = merge(tl,merge(new Treap(k,pri),root));
}

void dell(int k)
{
    Treap *tl,*tr;
    split(root,k-1,tl,root);
    split(root,k,root,tr);
    root = merge(tl,tr);
}

void show(Treap* t)
{
    if (!t) return;
    cout << t->key<<' ';
    show(t->lc);
    show(t->rc);
}

void debugg()
{
    cout << "  show treap : ";
    show(root);
    cout<<endl;
}

int a[523456];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    root = NULL;
    set<int> st;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        if (st.find(a[i]) != st.end())
        {
            assert(0);
        }
        st.insert(a[i]);
    }


    long long _ =0;
    for (int i=1;n>=i;i++)
    {
        int j;
        assert(root == NULL);
        for (j=i;n>=j;j++)
        {
            addd(a[j],-j);
            //cout << "i = "<<i<<" , j = "<<j<<" , ans = "<<cnt_ans()<<endl;
            v.clear();
            if (cnt_ans() == k) ++_;
            for (int _=i;j>=_;_++)
            {
                assert(v[_-i] == a[_]);
            }
            //else if (cnt_ans() > k) break;
        }
        //cout << "i = "<<i<<" , j = "<<j<<endl;
        for (int k=i;n>=k;k++)
        {
            dell(a[k]);
        }
    }
    printf("%lld\n",_);
    return 0;









    int last = 1;
    long long ans=0;
    int pre=0;
    for (int i=1;n>=i;i++)
    {
        //before adding
        addd(a[i],-i);
        //cout << "i = "<<i<<endl;
        //cout << "i = "<<i; debugg();
        //cout << "cnt_ans = "<<cnt_ans()<<endl;
        if (cnt_ans() < k) continue;
        else if (cnt_ans() == k)
        {
            ++pre;
            //cout << "gee" << endl;
        }
        else if (cnt_ans() > k)
        {
            dell(a[i]);
            //cout << "delete "<<i<<" , pre = "<<pre<<endl;
            while (cnt_ans() == k)
            {
                ans += max(pre,1);
                pre--;
                dell(a[last++]);
            }
            --i;
            pre = 0;
        }
    }
    while (cnt_ans() == k)
    {
        ans += max(pre,1);
        pre--;
        dell(a[last++]);
        //debugg();
        //cout << "pre = "<<pre<<endl;
    }
    //cout << "cnt_ans = "<<cnt_ans()<<endl;
    printf("%lld\n",ans);
}
