#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num=1;

ll mp(ll b,ll n,ll a=1){
    while(n){
        if(n&1)a*=b;
        b*=b; n>>=1;
    } return a;
}

int solve(ll num){
    int ans=0;
    for(ll b=2;1+b+b*b<=num;++b){
        ll base=1+mp(b,1);
        for(ll c=2;;++c){
            base+=mp(b,c);
            if(base>num)break;
            if(num%base==0 && num/base<=b-1)++ans;
        }
    }
    for(int ll x=1;x*(x+1)<num;++x)if(num%x==0)++ans;
    return ans;
}
ll read(){
    ll n=1;int k;cin>>k;
    while(k--){ll t;cin>>t;n*=t;}
    return n;
}

void unlock(int n){
    vector<int> cnt;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            int c=0;
            while(n%i==0){
                n/=i;
                ++c;
            }
            cnt.push_back(c);
        }
    }
    if(n!=1)cnt.push_back(1);
    // sort(cnt.begin(),cnt.end()); reverse(cnt.begin(),cnt.end());
    for(int i:cnt)cout<<" "<<i;cout<<endl;
}

bool app[1234];
int main(){
    // cout<<solve(read())<<endl;
    for(int i=2;i<=1000;++i){
        int ans=solve(i);
        // if(app[ans])continue;
        // app[ans]=1;
        cout<<i<<" : "<<ans<<" ->";
        unlock(i);
    }
}
