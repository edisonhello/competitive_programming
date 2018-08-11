#include <bits/stdc++.h>
using namespace std;

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

