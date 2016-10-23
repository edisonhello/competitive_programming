#include<bits/stdc++.h>
using namespace std;

string add(string a,string b){
    return "(("+a+"|"+a+")|("+b+"|"+b+"))";
}
string mt(string a,string b){
    return "(("+a+"|"+b+")|("+a+"|"+b+"))";
}
string _1(int n){
    if(n==0){
        return "((A0|B0)|(A0|B0))";
    }
    else{
        stringstream ss;
        string an,bn;
        ss<<"A";ss<<n;ss>>an;ss.clear();
        ss<<"B";ss<<n;ss>>bn;ss.clear();
        return add(
                   mt(an,bn),
                   mt(add(an,bn),_1(n-1))
               );
    }
}
string _2(int n){
    if(n==0){
        return "((A0|B0)|(A0|B0))";
    }
    else{
        stringstream ss;
        ss<<"((A";ss<<n;ss<<"|B";ss<<n;ss<<")|(";ss<<_2(n-1);ss<<"|((A";ss<<n;
        ss<<"|A";ss<<n;ss<<")|(B";ss<<n;ss<<"|B";ss<<n;ss<<"))))";
        string s;ss>>s;
        return s;
    }
}

int main(){
    int n;cin>>n;
    string ans1=_1(n);
    string ans2=_2(n);
    int nand1=0,nand2=0;
    for(char c:ans1)if(c=='|')++nand1;
    for(char c:ans2)if(c=='|')++nand2;
    cout<<"ans1:\n"
        <<ans1 <<'\n'
        <<nand1<<" NAND(s) used.\n";
    cout<<"ans2:\n"
        <<ans2 <<'\n'
        <<nand2<<" NAND(s) used.\n";
}
