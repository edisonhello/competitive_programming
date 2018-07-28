#include<bits/stdc++.h>
using namespace std;

int fake[33];

int main(){
    int m,n; cin>>m>>n;
    for(int i=0;i<n;++i){
        cout<<1<<endl;
        int t; cin>>t; 
        if(t==0)exit(0);
        if(t==-1)fake[i]=1;
    }
    int L=1,R=m,z=0;
    while(R>L){
        int M=(L+R)>>1;
        cout<<M<<endl;
        int t; cin>>t;
        if(fake[z%n])t*=-1; ++z;
        if(t==0)exit(0);
        if(t==1)L=M+1;
        else R=M-1;
    }
    cout<<L<<endl;
}
// 
