#include<iostream>
using namespace std;

#define int long long

int a[200005],xa[200005];

main(){
    int n,x;cin>>n>>x;
    if(!x){
        int tot=0;
        for(int i=0,t;i<n;++i){
            cin>>t;
            ++a[t];
        }
        for(int i=0;i<100003;++i){
            if(a[i])tot+=a[i]*(a[i]-1)/2;
        }
        cout<<tot<<endl;
    }
    else{
        int tot=0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            ++xa[x^a[i]];
        }
        for(int i=0;i<n;++i){
            tot+=xa[a[i]];
        }
        cout<<(tot>>1)<<endl;
    }
}
