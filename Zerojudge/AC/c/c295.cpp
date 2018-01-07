#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,s=0; cin>>n>>m;
    vector<int> cho;
    while(n--){
        set<int> st;
        for(int i=0;i<m;++i){
            int t; cin>>t;
            st.insert(t);
            if(st.size()>1)st.erase(st.begin());
        }
        s+=*st.begin();
        cho.push_back(*st.begin());
    }
    cout<<s<<endl;
    vector<int> ok;
    for(int i:cho){
        if(s%i==0)ok.push_back(i);
    }
    if(ok.empty())cout<<-1<<endl;
    else for(int i=0;i<ok.size();++i){
        cout<<ok[i]<<" \n"[i==ok.size()-1];
    }
}
