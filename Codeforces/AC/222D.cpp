#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005];
multiset<int> sa,sb;

int main(){
    int n,x; cin>>n>>x;
    for(int i=0;i<n;++i)cin>>a[i],sa.insert(a[i]);
    for(int i=0;i<n;++i)cin>>b[i],sb.insert(b[i]);
    sort(a,a+n); sort(b,b+n);
    
    int ua=-1,ub=-1,mn=1<<30;
    for(int i=0;i<n;++i){
        auto it=sb.lower_bound(x-a[i]);
        if(it==sb.end())continue;
        if(a[i]+*it<mn){
            mn=a[i]+*it;
            ua=a[i];
            ub=*it;
        }
    }
    sa.erase(sa.find(ua));
    sb.erase(sb.find(ub));
    int bigger=0;
    for(int i=0;i<n;++i){
        if(a[i]==ua){
            ua=-1;
            continue;
        }
        auto it=sb.lower_bound(mn-a[i]);
        if(it==sb.end()){
            sb.erase(sb.begin());
        }
        else{
            ++bigger;
            sb.erase(it);
        }
    }
    cout<<"1 "<<bigger+1<<endl;
}
