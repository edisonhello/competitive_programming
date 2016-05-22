#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;cin>>input;

    int q;cin>>q;

    while(q--){
        int l,r;cin>>l>>r;

        string sub = input;
        sub.assign(sub,l-1,r-l+1);
        //cout<<sub;
        stack<char> st;
        int cnt=0;
        for(int i=0;i<sub.length();i++){
            if(sub[i] == ')' && st.size()==0)continue;
            if(sub[i] == ')' && st.top()=='('){
                st.pop();
                cnt+=2;
                continue;
            }
            st.push(sub[i]);
            continue;
        }
        cout<<cnt<<endl;
    }
}
