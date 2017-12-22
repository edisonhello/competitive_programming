#include<bits/stdc++.h>
using namespace std;

int a[200];
int ptn[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i+n<60;++i){
        bool mtc=1;
        for(int j=0;j<n;++j){
            if(a[j]!=ptn[i+j]){mtc=0; break;}
        }
        if(mtc)return cout<<"yes"<<endl,0;
    } cout<<"no"<<endl;
}
