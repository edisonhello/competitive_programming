#include<iostream>
using namespace std;
#include<string>

int main(){
    int n;cin>>n;
    string s="";
    for(int i=1;i<=1000;++i){
        s=s+to_string(i);
    }
    cout<<s[n-1]<<endl;
}
