#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main(){
    cin>>s;
    reverse(s.begin(),s.end());
    while(!s.empty() && s[0]=='0')s.erase(s.begin());
    if(s.empty())cout<<"0"<<endl;
    else cout<<s<<endl;
}
