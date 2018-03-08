#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<1000006> notp;
vector<ll> prime;
void init(){
    notp[1]=1;
    for(ll i=2;i<1000000;++i){
        if(notp[i])continue;
        prime.push_back(i);
        for(ll j=i*i;j<1000000;j+=i){
            notp[j]=1;
        }
    }
}

ll mul(ll b,ll n,ll m,ll a=0){
    while(n){
        if(n&1)a=a+b,a-=(a>=m?m:0);
        b=b+b,b-=(b>=m?m:0); n>>=1;
    } return a;
}

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=mul(a,b,m);
        b=mul(b,b,m); n>>=1;
    } return a;
}

bool isprime(ll x){
    ll s=x-1,t=0;
    while(s%2==0)s/=2,++t;
    for(int _=0;_<12;++_){
        ll liar=rand()%x;
        if(liar==0)continue;
        liar=pw(liar,s,x);
        if(liar==1 || liar==x-1)continue;
        for(int i=1;i<t;++i){
            liar=mul(liar,liar,x);
            if(liar==x-1)break;
        }
        if(liar==x-1)continue;
        return 0;
    }
    return 1;
}

map<ll,int> pfac;
vector<ll> nleft,pqs;

void go(ll x){
    for(ll i:prime){
        while(x%i==0){
            ++pfac[i];
            x/=i;
        }
    }
    if(x==1)return;
    if(isprime(x))++pfac[x];
    else{
        ll sqx=sqrt(x);
        if(sqx*sqx==x){
            pfac[sqx]+=2;
        }
        else{
            nleft.push_back(x);
        }
    }
}

string spow(int x){
    string s="1"; s[0]-='0';
    while(x--){
        for(char &c:s)c*=2;
        for(int i=s.size()-1;i>0;--i){
            if(s[i]>9){
                s[i]-=10;
                ++s[i-1];
            }
        }
        while(s[0]>9){
            s[0]-=10;
            s="1"+s;
            s[0]-='0';
        }
    }
    return s;
}

int main(){
    init();
    int n; cin>>n;
    while(n--){
        ll t; cin>>t; 
        go(t);
    }
    for(ll x:nleft){
        bool ok=0;
        for(auto i:pfac){
            if(x%i.first==0){
                ++pfac[i.first];
                ++pfac[x/i.first];
                ok=1;
                break;
            }
        }
        if(ok)continue;
        for(int i=0;i<pqs.size();++i){
            ll g=__gcd(x,pqs[i]);
            if(g>1 && g!=x){
                pfac[g]+=2;
                ++pfac[x/g];
                ++pfac[pqs[i]/g];
                ok=1;
                pqs.erase(pqs.begin()+i);
                break;
            }
        }
        if(ok)continue;
        pqs.push_back(x);
    }
    for(int i=0;i<pqs.size();++i){
        for(auto ii:pfac){
            if(pqs[i]%ii.first==0){
                ++pfac[ii.first];
                ++pfac[pqs[i]/ii.first];
                pqs.erase(pqs.begin()+i);
                --i;
                break;
            }
        }
    }
    int mx=(pqs.size()?1:0);
    for(auto i:pfac)mx=max(mx,i.second);
    int cnt=0;
    for(auto i:pfac)if(i.second==mx)++cnt;
    if(mx==1)cnt+=pqs.size();
    cout<<mx<<endl;
    string ans=spow(cnt);
    --ans.back();
    for(char c:ans)cout<<char(c+'0'); cout<<endl;
}
