#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    map<char,int> mp;
    for(char c:s)++mp[c];
    if(mp.size()==1){
        cout<<"No"<<endl;
        exit(0);
    }
    if(mp.size()==2){
        bool is1=0;
        for(auto i:mp)if(i.second==1)is1=1;
        if(is1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        exit(0);
    }
    if(mp.size()==3){
        bool bg1=0;
        for(auto i:mp)if(i.second>1)bg1=1;
        if(bg1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        exit(0);
    }
    if(mp.size()==4){
        cout<<"Yes"<<endl;
        exit(0);
    }
    cout<<"No"<<endl;
}
