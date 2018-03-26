#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[41];
    for(int i=1;i<=4;++i)cin>>a[i];
    string s; cin>>s;
    int tot=0;
    for(char c:s){
        tot+=a[c-'0'];
    }
    cout<<tot<<endl;
}
