#include<bits/stdc++.h>
#define ll long long
#define L(x) log10((long double)(x))
using namespace std;

long double mn;
int main() {
    mn=L((1l<<31))+L((1<<30))+L(7);
    cout<<log10((double)(1l<<60))<<endl;;
    printf("%.2lfe+%03d\n",pow((long double)10,mn-(int)mn),(int)mn);
}
