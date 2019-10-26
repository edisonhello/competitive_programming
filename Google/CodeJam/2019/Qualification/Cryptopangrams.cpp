#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Ts; cin>>Ts; 
    for(int ts=1;ts<=Ts;++ts){
        int x,n; cin>>x>>n;
        vector<int> v(n);
        for(int &i:v)cin>>i;
        vector<int> u=v;
        u.resize(unique(u.begin(),u.end())-u.begin());
        vector<int> ps;
        for(int i=1;i<int(u.size());++i){
            ps.push_back(__gcd(u[i-1],u[i]));
        }
        ps.push_back(u.back()/ps.back());
        ps.push_back(u[0]/ps[0]);
        sort(ps.begin(),ps.end());
        ps.resize(unique(ps.begin(),ps.end())-ps.begin());
        assert(ps.size()==26u);
        int cur=u[0]/__gcd(u[0],u[1]);
        cout<<"Case #"<<ts<<": ";
        cout<<char(lower_bound(ps.begin(),ps.end(),cur)-ps.begin()+'A');
        for(int i:v){
            cur=i/cur;
            cout<<char(lower_bound(ps.begin(),ps.end(),cur)-ps.begin()+'A');
        }
        cout<<endl;
    }
}
