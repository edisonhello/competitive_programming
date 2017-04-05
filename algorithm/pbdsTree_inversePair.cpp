#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update> meow;

int main(){
    int n;while(cin>>n,n){
        meow.clear();
        ll ans=0;
        for(int i=0;i<n;++i){
            int t;cin>>t;
            meow.insert(t);
            ans+=meow.order_of_key(t);
        }
        cout<<ans<<endl;
    }
}
