#include<iostream>
using namespace std;
#define int long long
main(){
    int n,k;cin>>n>>k;bool prv=0;
    if(k>n/2)k=n-k;
    for(int now=1,wf=1,cur=0;;){
        cur+=k;
        if(prv)++wf,prv=0;
        if(cur>n)cur-=n,++wf,prv=1;
        now+=wf;
        cout<<now<<" ";
        if(cur==n)break;
    }
    cout<<endl;
}
