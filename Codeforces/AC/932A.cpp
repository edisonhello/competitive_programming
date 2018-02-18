#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s; cout<<s;
    s.pop_back(); reverse(s.begin(),s.end());
    cout<<s<<endl;
}
