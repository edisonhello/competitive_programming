#include<bits/stdc++.h>
using namespace std;

set<int> merge(set<int> &a,set<int> &b){
    auto i1=a.begin(),i2=b.begin();
    set<int> rt;
    while(i1!=a.end() && i2!=b.end()){
        if(*i1==*i2)rt.insert(*i1),++i1;
        else if(*i1<*i2)++i1;
        else ++i2;
    }
    return rt;
}

int main(){
    bool ok=0; int ans=0;
    set<int> st;
    for(int i='a';i<='z';++i)st.insert(i);
    int n; cin>>n; while(n--){
        string tp,s; cin>>tp>>s;
        if(tp=="!"){
            if(ok)++ans;
            set<int> stt;
            for(char c:s)stt.insert(c);
            st=merge(st,stt);
            if(st.size()==1)ok=1;
        }
        else if(tp=="."){
            for(char c:s)st.erase(c);
            if(st.size()==1)ok=1;
        }
        else{
            if(n && ok)++ans;
            st.erase(s[0]);
            if(st.size()==1)ok=1;
        }
    }
    cout<<ans<<endl;
}
