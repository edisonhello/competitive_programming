#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; string s; getline(cin,s); while(ts--){
        getline(cin,s);
        string t;
        for(char c:s){
            if(c>='A' && c<='Z')t+=c-'A'+'a';
            else if(c>='a' && c<='z')t+=c;
        }
        string str("chef");
        int cntt=0;
        for(int i=0;i<(int)t.size()-3;++i){
            set<char> st;
            for(int j=i;j<i+4;++j)st.insert(t[j]);
            bool ok=1;
            for(char c:str){
                if(st.find(c)==st.end()){
                    ok=0;
                    break;
                }
            }
            if(ok)++cntt;
        }
        if(cntt)cout<<"lovely "<<cntt<<endl;
        else cout<<"normal"<<endl;
    }
}
