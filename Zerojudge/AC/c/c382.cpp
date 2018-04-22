#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b; char c; while(cin>>a>>c>>b){
        if(c=='+')cout<<a+b;
        else if(c=='-')cout<<a-b;
        else if(c=='*')cout<<a*b;
        else if(c=='/')cout<<a/b;
        puts("");
    }
}
