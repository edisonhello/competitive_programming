#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double

struct line{
    ll a,b;
    ll get(ll x){return a*x+b;}
};
ld sect(line l1,line l2){
    return (ld)(l2.b-l1.b)/(l1.a-l2.a);
}

int main(){
    int n,m; while(cin>>n>>m,n){
        vector<line> ls;
        for(int i=0;i<n;++i){
            ll a,b; cin>>a>>b;
            ls.push_back({a,b});
        }
        sort(ls.begin(),ls.end(),[](const line &a,const line &b){return a.a==b.a?a.b>b.b:a.a<b.a;});
        int ptr=1;
        for(int i=1;i<n;++i){
            if(ls[i].a!=ls[i-1].a)ls[ptr]=ls[i],++ptr;
        }
        ls.resize(ptr);
        deque<line> us;
        for(line l:ls){
            if(0)while(us.size()>1u && sect(l,us[us.size()-2])<=sect(us[us.size()-2],us.back()))us.pop_back();
            while(us.size()>1u && (us[us.size()-2].b-l.b)*(us.back().a-us[us.size()-2].a)<=(us[us.size()-2].b-us.back().b)*(l.a-us[us.size()-2].a))us.pop_back();
            us.push_back(l);
        }
        vector<ll> c;
        while(m--){
            int t; cin>>t; c.push_back(t);
        }
        sort(c.begin(),c.end());
        ll ans=0;
        for(ll i:c){
            while(us.size()>1u && us[0].get(i)<us[1].get(i))us.pop_front();
            ans+=us[0].get(i);
        }
        cout<<ans<<endl;
    }
}
