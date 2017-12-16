#include <bits/stdc++.h>
#define ll long long
using namespace std;

bitset<1000006> _p;
vector<int> p;
void init(int n=1000006){
    for(ll i=2;i<1000006;++i){
        if(_p[i])continue;
        p.push_back(i);
        for(ll j=i*i;j<1000006;j+=i){
            _p[j]=1;
        }
    }
}
long meow(long x){
    ll rt=x;
    for(ll i:p){
        if(i*i>x)break;
        while(x%i==0){
            x/=i;
            rt+=x;
        }
    }
    if(x!=1)++rt;
    return rt;
}
long longestSequence(vector <long> a) {
    init();
    ll ans=0;
    for(auto i:a)ans+=meow(i);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<long> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    long result = longestSequence(a);
    cout << result << endl;
    return 0;
}

