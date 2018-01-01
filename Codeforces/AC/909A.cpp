#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b; cin>>a>>b;
    bool f=1;
    for(char c:a){
        if(c>=b[0] && !f)return cout<<b[0],0;
        cout<<c;
        f=0;
    }
    cout<<b[0];
}
