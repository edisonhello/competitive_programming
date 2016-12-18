#include<iostream>
using namespace std;

int main(){
    string aa[2];
    int a[2],c;
    cin>>aa[0]>>aa[1];
    for(int i=0;i<2;++i){
        if(aa[i]=="monday")a[i]=1;
        if(aa[i]=="tuesday")a[i]=2;
        if(aa[i]=="wednesday")a[i]=3;
        if(aa[i]=="thursday")a[i]=4;
        if(aa[i]=="friday")a[i]=5;
        if(aa[i]=="saturday")a[i]=6;
        if(aa[i]=="sunday")a[i]=0;
    }
    if(a[1]<a[0])a[1]+=7;
    c=a[1]-a[0];
    if(c==0||c==2||c==3)cout<<"YES\n";
    else cout<<"NO\n";
}
