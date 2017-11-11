#include<bits/stdc++.h>
using namespace std;

long double ch[100009];
int main(){
    int n,p; cin>>n>>p;
    long double ans=0,tot=0;
    for(int i=0;i<n;++i){
        int l,r; cin>>l>>r;
        ch[i]=1-((long double)(r/p-(l-1)/p))/(r-l+1);
    }
    for(int i=1;i<n;++i){
        ans+=ch[i]*ch[i-1];
    } ans+=ch[0]*ch[n-1];
    cout<<fixed<<setprecision(10)<<2000*(n-ans)<<endl;
}
