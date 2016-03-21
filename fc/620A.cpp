#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,s,q,w;
    cin>>a>>s>>q>>w;

    cout<<max(abs(a-q),abs(s-w))<<endl;
}
