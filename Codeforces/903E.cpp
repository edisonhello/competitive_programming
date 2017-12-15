#include<bits/stdc++.h>
using namespace std;

unordered_set<size_t> st;
unordered_map<size_t,int> mp;
int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int k,n; cin>>k>>n;
    int k=2,n=2500;
    string s; for(int i=1;i<=k;++i){
        // cin>>s;
        s=""; for(int i=0;i<n;++i)s+='a'+rand()%26;
        st.clear();
        for(int j=0;j<n;++j){
            for(int k=j+1;k<n;++k){
                swap(s[j],s[k]);
                st.insert(hash<string>{}(s));
                swap(s[j],s[k]);
            }
        }
        for(auto &s:st)++mp[s];
    }
    for(auto &i:mp)if(i.second==k)return cout<<i.first<<endl,0;
    cout<<-1<<endl;
}
