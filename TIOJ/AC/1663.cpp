#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b;
    while(cin>>t>>a>>b){
        if(t==1)cout<<a+b<<endl;
        else if(t==2)cout<<a-b<<endl;
        else if(t==3)cout<<a*b<<endl;
        else cout<<a%b<<endl;
    }
}
