#include<bits/stdc++.h>
using namespace std;

long long meoww(vector<long long> v){
    long long pos=LLONG_MIN,neg=LLONG_MAX,now=1;
    long long rt=v[0];
    for(long long i:v){
        now*=i;
        rt=max(rt,now);
        if(now>0 && pos!=LLONG_MIN)rt=max(rt,now/pos);
        if(now<0 && neg!=LLONG_MAX)rt=max(rt,now/neg);
        if(now>0)pos=max(pos,now);
        if(now<0)neg=min(neg,now);
    }
    return rt;
}

void meow(vector<long long> v){
    int n=v.size();
    long long ans=LLONG_MIN;
    for(long long i:v)ans=max(i,ans);
    for(int i=0,j=0;i<n;i=j){
        if(v[i]==0){
            ++j;
            continue;
        }
        while(j<n && v[j]!=0)++j;
        vector<long long> vv;
        for(int z=i;z<j;++z){
            vv.push_back(v[z]);
        }
        ans=max(ans,meoww(vv));
    }
    cout<<ans<<endl;
}

int main(){
    int t; while(cin >> t){
    string s; getline(cin, s);
    while (t--) {
        getline(cin, s);
        vector<long long> v;
        long long x;
        stringstream ss(s);
        while (ss >> x) v.push_back(x);
        meow(v);
    } }
}
