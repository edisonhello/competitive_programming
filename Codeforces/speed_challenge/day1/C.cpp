#include<bits/stdc++.h>
using namespace std;

int main(){
    int c1,c2,c3,c4,c5; cin>>c1>>c2>>c3>>c4>>c5;
    int t=c1+c2+c3+c4+c5;
    if(t%5 || t==0)cout<<-1<<endl;
    else cout<<t/5<<endl;
}
