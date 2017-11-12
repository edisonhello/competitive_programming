struct Catalan{
    static ll mod;
    vector<ll> fac,inv;
    ll pow(ll b,ll n=-2,ll a=1){
        while(n){
            if(n&1)a=a*b%mod;
            b=b*b%mod; n>>=1;
        } return a;
    }
    void init(int n,ll m){
        ll mod=m;
        fac.resize((n<<1)+10);
        inv.resize(n+10);
        fac[0]=fac[1]=1; for(int i=2;i<=(n<<1)+2;++i)fac[i]=fac[i-1]*i%mod;
        inv[n+5]=pow(inv[n+5]); for(int i=n+4;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
    }
    ll get(int n){
        ll mod;
        return fac[n<<1]*inv[n+1]%mod*inv[n]%mod;
    }
}
