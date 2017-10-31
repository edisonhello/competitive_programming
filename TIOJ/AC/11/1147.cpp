#include<bits/stdc++.h>
using namespace std;
int x[1111],y[1111];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    int ax,ay,aa=1e9+87;
    for(int i=0;i<n;++i){
        int ta=0;
        for(int j=0;j<n;++j){
            ta+=abs(x[i]-x[j])+abs(y[i]-y[j]);
        }
        if(ta<aa)aa=ta,ax=x[i],ay=y[i];
        else if(ta==aa && x[i]<ax)ax=x[i],ay=y[i];
        else if(ta==aa && x[i]==ax && y[i]<ay)ay=y[i];
    }
    cout<<ax<<" "<<ay<<endl<<aa<<endl;
}
