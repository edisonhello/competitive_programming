#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ks=0; while(cin>>n,n){
        vector<int> v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        set<int> st;
        for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)st.insert(v[i]+v[j]);
        cout<<"Case "<<(++ks)<<":"<<endl;
        int q; cin>>q; while(q--){
            int x; cin>>x;
            auto it=st.lower_bound(x);
            int val=-99999;
            if(it!=st.end()){
                val=*it;
            }
            if(it!=st.begin()){
                --it;
                if(abs(val-x)>abs(*it-x))val=*it;
            }
            cout<<"Closest sum to "<<x<<" is "<<val<<"."<<endl;
        }
    }
}
