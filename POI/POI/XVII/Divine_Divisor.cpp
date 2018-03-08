#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,int> pfac;

bitset<1000005> notp;
vector<int> prime;
void init(){
    notp[1]=1;
    for(int i=2;i<1000000;++i){
        if(notp[i])continue;
        prime.push_back(i);
        for(ll j=i*1ll*i;j<1000000;j+=i){
            notp[j]=1;
        }
    }
}

ll mul(ll b,ll n,ll m,ll a=0){
    for(;n;n>>=1,b=(b+b)%m)if(n&1)a=(a+b)%m;
    return a;
}

ll pw(ll b,ll n,ll m){
    ll a=1;
    for(;n;n>>=1,b=mul(b,b,m))if(n&1)a=mul(a,b,m);
    return a;
}

bool rabin(ll x){
    if(x==2)return 1;
    if(x%2==0)return 0;
    ll s=x-1,r=0;
    while(s%2==0)s/=2,++r;
    for(int _=0;_<12;++_){
        ll liar=rand()%x;
        if(liar==0)continue;
        liar=pw(liar,s,x);
        if(liar==1 || liar==x-1)continue;
        for(int i=1;i<r;++i){
            liar=mul(liar,liar,x);
            if(liar==x-1)break;
        }
        if(liar==x-1)continue;
        return 0;
    }
    return 1;
}

ll bf(ll x){
    for(ll i:prime){
        // if(i*i>x)break;
        while(x%i==0){
            ++pfac[i];
            x/=i;
        }
    }
    // if(x>1000000)return x;
    if(x!=1)return x;
    else return 0;
}

ll rho(ll x,ll c=3){
    auto f=[&](ll a){return (mul(a,a,x)+c)%x;};
    auto ff=[&](ll a){return f(f(a));};
    ll a=f(rand()),b=f(a);
    while(1){
        a=f(a); b=ff(b);
        ll g=__gcd(abs(a-b),x);
        if(g!=1)return g==x?rho(x,c+1):g;
    }
}

vector<ll> bigp;
vector<ll> trash;
bitset<666> ok;

void go(ll x){
    if(rabin(x)){
        ++pfac[x];
        return;
    }
    x=bf(x);
    ll xx=sqrt(x);
    if(x>0 && xx*xx==x){
        pfac[xx]+=2;
        bigp.push_back(xx);
        x=0;
    }
    if(x)trash.push_back(x);
}

string spw(int n){
    string rt="1"; rt[0]-='0';
    for(int i=0;i<n;++i){
        for(char &c:rt)c*=2;
        int ptr=rt.size()-1;
        while(ptr>0){
            if(rt[ptr]>9){
                rt[ptr]-=10;
                ++rt[ptr-1];
            }
            --ptr;
        }
        while(rt[0]>9){
            rt[ptr]-=10;
            rt="1"+rt;
            rt[0]-='0';
        }
    }
    return rt;
}

void testmode(){
    ll x; cin>>x;
    go(x);
    for(auto i:pfac)cout<<i.first<<" "<<i.second<<endl;
}

map<ll,int> trashmap;

int main(){
    init();
    // testmode();
    int n; cin>>n;
    while(n--){
        ll t; cin>>t;
        go(t);
    }
    for(int i=0;i<trash.size();++i){
        if(ok[i])continue;
        for(int j=i+1;j<trash.size();++j){
            if(ok[j])continue;
            ll g=__gcd(trash[i],trash[j]);
            if(g>1 && g!=trash[i]){
                pfac[g]+=2;
                ++pfac[trash[i]/g];
                ++pfac[trash[j]/g];
                bigp.push_back(g);
                bigp.push_back(trash[i]/g);
                bigp.push_back(trash[j]/g);
                ok[i]=1; ok[j]=1;
                break;
            }
        }
    }
    for(int i=0;i<trash.size();++i){
        if(ok[i])continue;
        for(ll PPP:bigp){
            if(trash[i]%PPP==0){
                ++pfac[PPP];
                ++pfac[trash[i]/PPP];
                ok[i]=1;
                break;
            }
        }
    }
    for(ll i:trash)++trashmap[i];
    int mx=0,trashmx=0;
    for(auto i:trashmap)trashmx=max(trashmx,i.second);
    for(auto i:pfac)mx=max(mx,i.second);
    ll cnt=0;
    if(mx>trashmx){
        for(auto i:pfac)if(i.second==mx)++cnt;
    }
    else if(trashmx>mx){
        for(auto i:trashmap)if(i.second==trashmx)cnt+=2;
    }
    else{
        for(auto i:pfac)if(i.second==mx)++cnt;
        for(auto i:trashmap)if(i.second==trashmx)cnt+=2;
    }
    cout<<max(mx,trashmx)<<endl;
    string ans=spw(cnt);
    --ans.back();
    for(char c:ans)cout<<char(c+'0');
    cout<<endl;

}
// no AC
