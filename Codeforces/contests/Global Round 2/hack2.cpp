#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> s;
map<int,int> ms;

int main(){
    int n;
    cin >>n;
    int ans=0;
    for(int i=0;i<n;++i){
        int a; cin>>a;
        if(ms.count(a)){

        }
        else{
            s.insert(make_pair(i,a));
            ms[a]=i;
        }
        for(auto it:s){
            if(it.second==a){
                continue;
            }
            ans=max(ans,i-it.first);
            break;
        }
    }
    cout<<ans<<endl;
}
