#include<bits/stdc++.h>
using namespace std;
int ans[]={2,3,4,6,8,14,20,36,60,108,188,352,632,1182,2192,4116,7712,14602,27596,52488,99880,190746,367424,699252,1342184,2581428,4971068,9587580};
int b[88],c[88],d[88],e[88];
int main(){
//    for(int i=1;i<28;++i){
//        cout<<ans[i-1]*2-ans[i]<<" ";
//    }cout<<endl;
//    for(int i=1;i<28;++i){
//        cout<<(b[i-1]=ans[i]-ans[i-1])<<" ";
//    }cout<<endl;
//    for(int i=1;i<26;++i){
//        cout<<(c[i-1]=b[i]-b[i-1])<<" ";
//    }cout<<endl;
//    for(int i=1;i<25;++i){
//        cout<<(d[i-1]=c[i]-c[i-1])<<" ";
//    }cout<<endl;
//    for(int i=1;i<24;++i){
//        cout<<(e[i-1]=d[i]-d[i-1])<<" ";
//    }cout<<endl;
//    for(int i=1;i<23;++i){
//        cout<<(e[i]-e[i-1])<<" ";
//    }cout<<endl;
    int n;cin>>n;
    cout<<ans[n-1]<<endl;
}
