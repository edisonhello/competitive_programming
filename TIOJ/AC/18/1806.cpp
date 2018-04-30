#include<bits/stdc++.h>
using namespace std;

int go(string s,int l,int r){
    // cout<<"go "<<l<<" "<<r<<endl;
    ++l, --r;
    if(s[l]!='['){
        stringstream ss(s.substr(l,r-l+1));
        int x; ss>>x; return x/2+1;
    }
    vector<int> z;
    while(l<r){
        int c=1;
        int ol=l;
        // cout<<"start l: "<<ol<<endl;
        ++l;
        while(c){
            if(s[l]=='[')++c;
            if(s[l]==']')--c;
            ++l;
        }
        z.push_back(go(s,ol,l-1));
    }
    int c=z.size()/2+1;
    sort(z.begin(),z.end());
    int t=0;
    for(int i=0;i<c;++i)t+=z[i];
    return t;
}

int main(){
    int ts; cin>>ts; while(ts--){
        string s; cin>>s; 
        cout<<go(s,0,s.size()-1)<<endl;
    }
}
