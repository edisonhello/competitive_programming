#pragma GCC optimize("O")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<100000> notprime;
vector<int> prime;
void init(){
    for(int i=2;i<=10000;++i){
        if(notprime[i])continue;
        prime.push_back(i);
        for(int j=i*i;j<=10000;j+=i){
            notprime[j]=1;
        }
    }
}

ll val[2234][22];

ll pw(ll b,ll n,ll a=1){
    while(n){
        if(n&1){
            ll a_tmp=a*b;
            if(a_tmp>1000000000000000000ll || a_tmp/a!=b || a_tmp/b!=a)return 2000000000000000000ll;
            a=a_tmp;
        }
        ll b_tmp=b*b; n>>=1;
        if(n){
            if(b>2147483647ll)return 2000000000000000000ll;
            b=b_tmp;
        }
    }
    return a;
}

const ll lmax=2000000000000000000ll;

int main(){
    init();
    int n; cin>>n;
    if(n==1)return cout<<1<<endl,0;
    val[0][0]=1;
    for(int i=1;i<=10;++i)val[0][i]=1;
    ll ans=lmax;
    for(int i=1;i<=n;++i){
        val[i][0]=pw(2,i-1);
        if(i==n)ans=min(ans,val[i][0]);
        for(int j=1;j<=10;++j){
            val[i][j]=lmax;
            for(int k=2;k<n;++k){
                if(i%k)continue;
                ll powres=pw(prime[j],k-1);
                // cout<<"powres: "<<powres<<endl;
                if(powres>1000000000000000000ll){
                    val[i][j]=min(val[i][j],powres);
                }
                else{
                    ll newv=val[i/k][j-1]*powres;
                    // cout<<"newv: "<<newv<<endl;
                    // cout<<"newv/powres: "<<(newv/powres)<<endl;
                    // cout<<"in if "<<(newv/powres!=val[i/k][j-1])<<endl;
                    if(newv/powres!=val[i/k][j-1]){
                        val[i][j]=min(val[i][j],1233123123123123123ll);
                    }
                    else val[i][j]=min(val[i][j],newv);
                }
            }
            // cout<<i<<" "<<j<<" "<<val[i][j]<<endl;
            if(i==n)ans=min(ans,val[i][j]);
        }
    }

    cout<<ans<<endl;
}
