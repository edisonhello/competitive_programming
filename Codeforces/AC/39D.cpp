#include<bits/stdc++.h>
using namespace std;

int main(){
    int q,w,e,a,s,d;
    cin>>q>>w>>e>>a>>s>>d;
    int dif=q!=a;
    dif+=w!=s;
    dif+=e!=d;
    if(dif<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
