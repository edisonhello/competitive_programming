#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<int> a,b;
    for(int i=0;i<s.size()-1;++i){
        if(s[i]=='A' and s[i+1]=='B')a.push_back(i);
        if(s[i]=='B' and s[i+1]=='A')b.push_back(i);
    }
    for(int i:a){
        for(int j:b){
            if(abs(i-j)>1)return cout<<"YES"<<endl,0;
        }
    }
    cout<<"NO"<<endl;
}
