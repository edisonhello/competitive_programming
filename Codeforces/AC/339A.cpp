#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    vector<char> s;
    for(int i=0;i<a.length();i+=2){
        s.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i];
        if(i!=s.size()-1)cout<<"+";
    }cout<<endl;
}
