#include<iostream>
#include<sstream>
using namespace std;
string s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(getline(cin,s)){
        if(s[0]=='0')break;
        stringstream ss;
        ss<<s;
        int a,tot=0,cnt=0,fst=0;
        while(ss>>a && a){
            tot+=a;
            cnt++;
            if(!fst)fst=a;
        }
        cout<<fst<<" "<<cnt<<" "<<tot<<'\n';
    }
}
