#include<bits/stdc++.h>
using namespace std;

bitset<20000007> np;
vector<int> _p;

void init(int n=20000007){
    for(int i=2;i<20000007;++i){
        if(np[i])continue;
        _p.push_back(i);
        for(long long j=1ll*i*i;j<20000007;j+=i){
            np[j]=1;
        }
    }
}

void meow(long long n){
    int ans=1;
    for(int i:_p){
        if(1ll*i*i>n)break;
        if(n%i==0){
            int cnt=1;
            while(n%i==0)n/=i,++cnt;
            ans*=cnt;
        }
    }
    cout<<ans*(n==1?1:2)<<endl;
}

int main(){
    init();
    long long n; while(cin>>n,(n && cout<<n<<" "))meow(4*n-3);
}
