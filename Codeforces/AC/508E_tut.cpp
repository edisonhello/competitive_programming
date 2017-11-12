#include<bits/stdc++.h>
using namespace std;
void jizz(){cout<<"IMPOSSIBLE"<<endl; exit(0);}

int l[666],r[666];
stack<string> st;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>l[i]>>r[i];
    for(int i=n;i>=1;--i){
        string s="(";
        while(st.size() and s.size()<l[i])s+=st.top(),st.pop();
        if(!(l[i]<=s.size() and s.size()<=r[i]))jizz();
        st.push(s+")");
    }
    while(st.size())cout<<st.top(),st.pop(); cout<<endl;
}
