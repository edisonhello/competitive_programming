#include<bits/stdc++.h>
using namespace std;
map<int,long long> a,b;
int main(){
    int n; cin>>n; int x,y; while(n--){
        cin>>x>>y;
        a[x+y]++; b[x-y]++;
    }
    long long ans=0;
    for(auto &i:a)ans+=i.second*(i.second-1)/2;
    for(auto &i:b)ans+=i.second*(i.second-1)/2;
    cout<<ans<<endl;
}
