#include<bits/stdc++.h>
using namespace std;

unsigned int _a,_b;
int rnd(){
    unsigned r=(_a<<14)|(_a>>18);
    _b=(r*_a+7122)^0xdeadbeef;
    _a=((_a*r)>>19)^_b;
    return (_a*_b)&INT_MAX;
}

int main(){
    // srand(clock());
    cin>>_a>>_b;
    // 601562990 343870197
    // _a=601562990, _b=343870197;
    int n=300000,k=rnd()%n+1;
    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;++i)cout<<rnd()%10000001<<" "; cout<<endl;
}
