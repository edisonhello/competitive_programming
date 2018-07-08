#include <bits/stdc++.h>
using namespace std;

int main ()
{
    srand(clock());
    int T = 50;
    cout << T << endl;
    for (int i=0;T>i;i++)
    {
        int n = rand()%50+1;
        int k = rand()%n+1;
        long long v = rand();
        v <<= 30;
        v |= rand();
        v %= (1000000000000LL) + 1;
        cout << n << ' ' << k << ' ' << v << endl;
        for (int i=1;n>=i;i++)
        {
            string s;
            int len = rand()%10 + 1;
            while (len--) s.push_back(rand()%26 + 'a');
            cout << s << endl;
        }
    }
}
