#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long pw(long long b,long long n,long long m=mod,long long a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

long long inv(long long x){
    return pw(x,mod-2,mod);
}

void pow(vector<long long> &a,vector<long long> &b,vector<long long> &res){
    if(a.size()!=b.size())exit(7122);
    if(a.size()<=2){
        res.resize(a.size()<<1,0);
        for(int i=0;i<a.size();++i){
            for(int j=0;j<b.size();++j){
                res[i+j]+=a[i]*b[j]%mod;
            }
        }
        for(auto &i:res)i%=mod;
        return;
    }

    // cout<<"a:  "; for(long long i:a)cout<<i<<" "; cout<<endl;
    // cout<<"b:  "; for(long long i:b)cout<<i<<" "; cout<<endl;
    int hlen=a.size()>>1;
    res.resize(a.size()*2,0);
    vector<long long> ta(hlen),tb(hlen),BD,AC,ABCD;
    for(int i=0;i<hlen;++i)ta[i]=a[i],tb[i]=b[i];
    // cout<<"ta: "; for(long long i:ta)cout<<i<<" "; cout<<endl;
    // cout<<"tb: "; for(long long i:tb)cout<<i<<" "; cout<<endl;
    pow(ta,tb,BD);
    // cout<<"BD: "; for(long long i:BD)cout<<i<<" "; cout<<endl;
    for(int i=0;i<BD.size();++i)res[i]+=BD[i];
    for(int i=0;i<hlen;++i)ta[i]=a[i+hlen],tb[i]=b[i+hlen];
    // cout<<"ta: "; for(long long i:ta)cout<<i<<" "; cout<<endl;
    // cout<<"tb: "; for(long long i:tb)cout<<i<<" "; cout<<endl;
    pow(ta,tb,AC);
    // cout<<"AC: "; for(long long i:AC)cout<<i<<" "; cout<<endl;
    for(int i=0;i<AC.size();++i)res[i+(hlen<<1)]+=AC[i];
    for(int i=0;i<hlen;++i)ta[i]=(a[i]+a[i+hlen])%mod,tb[i]=(b[i]+b[i+hlen])%mod;
    // cout<<"ta: "; for(long long i:ta)cout<<i<<" "; cout<<endl;
    // cout<<"tb: "; for(long long i:tb)cout<<i<<" "; cout<<endl;
    pow(ta,tb,ABCD);
    // cout<<"--: "; for(long long i:ABCD)cout<<i<<" "; cout<<endl;
    for(int i=0;i<ABCD.size();++i)res[i+hlen]+=ABCD[i]-AC[i]-BD[i];
    for(auto &i:res){
        i%=mod;
        if(i<0)i+=mod;
    }
    // cout<<"re: "; for(long long i:res)cout<<i<<" "; cout<<endl;
    return;
}

long long a[55555],xi[55555];

int main(){
    int n; long long k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    long long cu=k-1,cn=0,c=1;
    for(int i=1;i<=n;++i){
        xi[i]=c;
        ++cu, ++cn;
        cu%=mod;
        c=c*cu%mod*inv(cn)%mod;
    }
    int N=n; while(N!=(N&-N))N+=N&-N;
    // cout<<"N: "<<N<<endl;
    vector<long long> aa(N,0),bb(N,0),res;
    for(int i=1;i<=n;++i)aa[i-1]=a[i];
    for(int i=1;i<=n;++i)bb[i-1]=xi[i];
    pow(aa,bb,res);
    for(int i=0;i<n;++i)cout<<res[i]<<'\n';
}
