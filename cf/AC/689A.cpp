#include<bits/stdc++.h>
using namespace std;
int main(){
    int l;cin>>l;
    string s;cin>>s;

    if((s.find('1')<123||s.find('2')<235||s.find('3')<125)&&(s.find('7')<123||s.find('0')<235||s.find('9')<125)&&(s.find('1')<123||s.find('4')<235||s.find('7')<125||s.find('0')<125)&&(s.find('3')<123||s.find('6')<235||s.find('9')<125||s.find('0')<125)){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}
