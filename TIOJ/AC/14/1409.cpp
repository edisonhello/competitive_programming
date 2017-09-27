#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; while(cin>>n){
        stack<ll> st;
        ll tot=0;
        while(n--){
            ll t; cin>>t; st.push(t);
            tot+=t;
        }
        bool jizz=0;
        while(st.size()){
            if(st.top()>=(tot+1)/2)jizz=1;
            st.pop();
        }
        if(!jizz)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
