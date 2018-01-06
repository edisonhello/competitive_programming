#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    unordered_set<string> st;
    while(n--){
        string s; cin>>s;
        st.insert(s);
    }
    cin>>n; while(n--){
        string s; cin>>s;
        if(st.find(s)==st.end()){
            cout<<"no\n";
            st.insert(s);
        }
        else cout<<"yes\n";
    }
}
