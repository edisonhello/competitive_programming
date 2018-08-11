#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *lc,*rc;
    int val;
    Node(int _val):lc(NULL),rc(NULL),val(_val){}
};

Node* root;

void gao(Node* node,int key)
{
    if (node->val < key)
    {
        if (node->rc == NULL)
        {
            node->rc = new Node(key);
            return;
        }
        else gao(node->rc,key);
    }
    else if (node->val > key)
    {
        if (node->lc == NULL)
        {
            node->lc = new Node(key);
            return;
        }
        else gao(node->lc,key);
    }
}

vector<int> v;

int cal(Node* node)
{
    if (!node) return 0;
    v.push_back(node->val);
    int ret = cal(node->lc);
    ret += cal(node->rc);
    if (node->lc == NULL && node->rc == NULL) ret++;
    return ret;
}

void addd(int key)
{
    if (root == NULL) root = new Node(key);
    else gao(root,key);
}

int a[523456];

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    root = NULL;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    long long _ =0;
    for (int i=1;n>=i;i++)
    {
        root = NULL;
        for (int j=i;n>=j;j++)
        {
            addd(a[j]);
            v.clear();
            if (cal(root) == k)
            {
                bool can = true;
                for (int l=i;j>=l;l++)
                {
                    if (v[l-i] != a[l]) can = false;
                }
                if (can)++_;
            }
            /*
            cout << "ori : ";
            for (int l=i;j>=l;l++) cout << a[l]<<' ';
            cout << endl;
            cout << "dfs : ";
            for (int i:v) cout << i << ' ';
            cout << endl;
            */
        }
        //cout << "i = "<<i<<endl;
    }
    printf("%lld\n",_);
}
