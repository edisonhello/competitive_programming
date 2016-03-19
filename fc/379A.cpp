#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int lft=0;
    int tb=0;

    while(a){
        lft+=a;
        tb+=a;
        a=0;
        a+=lft/b;
        lft%=b;
    }
    cout<<tb<<endl;
}
