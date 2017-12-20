#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d,now=0; cin>>n>>d;
    while(n--){
        int a,b; cin>>a>>b;
        if(a<=now)now=max(now,b);
    }
    if(now>=d)cout<<"YeS"<<endl;
    else cout<<"nO"<<endl;
}
