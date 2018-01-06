#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; string s; cin>>k>>s;
    vector<int> seg;
    for(char &c:s)if(c>='A' && c<='Z')c='A'; else c='a';
    for(int i=0,j;i<s.size();i=j){
        for(j=i;j<s.size() && s[i]==s[j];++j);
        seg.push_back(j-i);
    }
    seg.push_back(0);
    int ans=0,now=0;
    for(int len:seg){
        if(len<k){
            ans=max(ans,now);
            now=0;
        }
        else if(len==k){
            now+=len;
        }
        else{
            now+=k;
            ans=max(ans,now);
            now=k;
        }
    }
    cout<<ans<<endl;
}
