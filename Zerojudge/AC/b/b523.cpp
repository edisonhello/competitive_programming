#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> st;
    string s; while(getline(cin,s)){
        if(st.find(s)==st.end())cout<<"NO"<<endl,st.insert(s);
        else cout<<"YES"<<endl;
    }
}
