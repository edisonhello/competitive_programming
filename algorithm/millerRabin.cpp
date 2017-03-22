// UVa 10140
ll p(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

bool isp(ll n){
    if(n==1)return 0;
    if(n==2)return 1;
    if(!(n&1))return 0;
    ll nn=n-1,t=0;
    while(!(nn&1))nn>>=1,++t;
    ll ts[]={2,7,61};
    for(int tt=0;tt<3;++tt){
        ll a=ts[tt]%n;
        if(a==0||a==1||a==n-1)continue;
        ll x=p(a,nn,n);
        if(x==1||x==n-1)continue;
        for(int i=0;i<t-1;++i){
            x=x*x%n;
            if(x==1)return 0;
            if(x==n-1)break;
        }
        if(x==n-1)continue;
        return 0;
    } return 1;
}

ll L,U;
vector<ll> ip;
int main(){
    assert(isp(561)==0);
    while(cin>>L>>U){
        ip.clear();
        for(ll i=L;i<=U;++i)if(isp(i))ip.pb(i);
        if(ip.size()<2u)cout<<"There are no adjacent primes.\n";
        else{
            ll mn=99999999999ll,mx=0,mnl=-1,mnr=-1,mxl=-1,mxr=-1;
            for(int i=1;i<ip.size();++i){
                if(mn>ip[i]-ip[i-1]){
                    mnl=ip[i-1], mnr=ip[i];
                    mn=ip[i]-ip[i-1];
                }
                if(mx<ip[i]-ip[i-1]){
                    mxl=ip[i-1], mxr=ip[i];
                    mx=ip[i]-ip[i-1];
                }
            }
            printf("%lld,%lld are closest, %d,%d are most distant.\n",mnl,mnr,mxl,mxr);
        }
    }
}
