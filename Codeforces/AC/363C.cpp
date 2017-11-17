#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    char nc=-1; int prv=0,now=0;
    for(char c:s){
        if(nc==c){
            if(now>=2 or (prv>1 and now>=1));
            else cout<<c,++now;
        }
        else{
            prv=now;
            nc=c;
            now=1;
            cout<<c;
        }
    }
}
