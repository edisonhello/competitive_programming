// copy from UVa 673
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n; cin>>n; getline(cin,s); while(n--){
        getline(cin,s);
        stack<char> st;
        bool ok=1;
        for(char c:s){
            if(c=='(' || c=='[')st.push(c);
            else if(c==')')if(st.size() && st.top()=='(')st.pop(); else {ok=0; break;}
            else if(c==']')if(st.size() && st.top()=='[')st.pop(); else {ok=0; break;}
        }
        if(ok && st.empty())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
