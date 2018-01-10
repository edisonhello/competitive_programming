#include<bits/stdc++.h>
using namespace std;

bitset<20000007> np;
vector<int> _p;
int minprime[20000007];

void init(int n=20000007){
    for(int i=2;i<20000007;++i){
        if(np[i])continue;
        _p.push_back(i);
        minprime[i]=i;
        for(long long j=1ll*i*i;j<20000007;j+=i){
            minprime[j]=i;
            np[j]=1;
        }
    }
}

void meow(long long n){
    int ans=1;
    for(int i:_p){
        if(n<20000007 || 1ll*i*i>n)break;
        if(n%i==0){
            int cnt=1;
            while(n%i==0)n/=i,++cnt;
            ans*=cnt;
        }
    }
    if(n>=20000007)return cout<<ans*2<<endl,void();
    map<int,int> mp;
    while(minprime[n]){
        ++mp[minprime[n]];
        n/=minprime[n];
    }
    for(auto it:mp){
        ans*=it.second+1;
    }
    cout<<ans<<endl;
}

int main(){
    init();
    long long n; while(cin>>n,(n && cout<<n<<" "))meow(4*n-3);
}
