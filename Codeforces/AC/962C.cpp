#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;  cin>>s;
    int ans=111;
    for(int i=0;i<(1<<s.size());++i){
        string t;
        for(int j=0;j<s.size();++j){
            if((1<<j)&i){
                t+=s[j];
            }
        }
        if(t.empty() || t[0]=='0')continue;
        stringstream ss(t);
        int z; ss>>z;
        int q=round(sqrt(z));
        if(q*q==z)ans=min(ans,int(s.size()-t.size()));
    }
    if(ans==111)ans=-1;
    cout<<ans;
}
