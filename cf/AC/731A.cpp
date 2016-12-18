#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string s;
int main(){
    cin>>s;
    char now='a';
    int d,a=0;
    for(char c:s){
        d=now-c;
        a+=min({abs(d),abs(abs(d)-26)});
        now=c;
    }
    cout<<a<<endl;
}
