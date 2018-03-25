#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    st.insert(60);
    st.insert(90);
    st.insert(108);
    st.insert(120);
    for(int i=7;i<=7122;++i){
        int al=(i-2)*180;
        if(al%i==0)st.insert(al/i);
    }
    int n; cin>>n; while(n--){
        int t; cin>>t;
        if(st.find(t)!=st.end()){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
