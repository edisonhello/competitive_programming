#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main(){
    cin>>s;
    cout<<s;
    reverse(s.begin(),s.end());
    cout<<s.substr(1,s.length()-1)<<endl;;
}
