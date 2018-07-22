#include<bits/stdc++.h>
using namespace std;

void bf(int n){
    set<pair<int,int>> st;
    for(int a=0;a<=n;++a){
        for(int b=0;b<=n;++b){
            if(a+b>n)continue;
            st.insert(pair<int,int>(a+b,a^b));
        }
    }
    cout<<n<<" ";
    cout<<st.size()<<endl;
}

const long long mod=1e9+7;

long long b(long long n){
    cout<<"b("<<n<<")"<<endl;
    static map<long long,long long> mp;
    auto it=mp.find(n);
    if(it!=mp.end())return it->second;
    if(n<2)return mp[n]=n;
    if(!(n&1))return mp[n]=b(n/2);
    else return mp[n]=(b((n-1)>>1)+b((n+1)>>1))%mod;
}

long long a(long long n){
    cout<<"a("<<n<<")"<<endl;
    static map<long long,long long> mp;
    auto it=mp.find(n);
    if(it!=mp.end())return it->second;
    return mp[n]=(b(n+1)+(n>0?a(n-1):0))%mod;
}

int main(){
    // for(int i=1;i<=50;++i)bf(i);
    long long n; cin>>n;
    cout<<a(n)<<endl;
}
