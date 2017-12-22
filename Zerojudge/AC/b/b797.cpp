#include<bits/stdc++.h>
using namespace std;

struct type{
    vector<long long> v;
    type& operator=(const int &x){
        v.clear(); v.push_back(x);
    }
    type& operator+=(const type &b){
        vector<long long> rt(max(v.size(),b.v.size()));
        for(int i=0;i<rt.size();++i){
            rt[i]=(i<v.size()?v[i]:0)+(i<b.v.size()?b.v[i]:0);
        }
        for(int i=0;i<rt.size()-1;++i)if(rt[i]>=1000000000000000ll){
            rt[i+1]+=rt[i]/1000000000000000ll;
            rt[i]%=1000000000000000ll;
        }
        while(rt.back()>=1000000000000000ll){
            rt.push_back(rt.back()/1000000000000000ll);
            rt[rt.size()-2]%=1000000000000000ll;
        }
        this->v=rt;
        return *this;
    }
};

type dp[40005];

void output(type &ot){
    cout<<ot.v.back();
    for(int i=ot.v.size()-2;i>=0;--i)printf("%015lld",ot.v[i]);
    cout<<endl;
}
int main(){
    dp[0]=1;
    for(int i=1;i*i<40005;++i){
        int v=i*i;
        for(int j=v;j<40005;++j){
            dp[j]+=dp[j-v];
        }
    }
    int t; cin>>t; while(t--){
        int n; cin>>n;
        output(dp[n]);
    }
}
