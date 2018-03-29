#include<bits/stdc++.h>
using namespace std;

int w[1<<21],d[1<<21];

int main(){
    int n; while(cin>>n,n){
        memset(d,0,sizeof(d));
        for(int i=0;i<(1<<n);++i){
            cin>>w[i];
        }
        d[0]=w[0];
        for(int i=0;i<(1<<n);++i){
            for(int j=0;j<n;++j){
                if(!(i&(1<<j))){
                    d[i|(1<<j)]=max(d[i|(1<<j)],d[i]+w[i|(1<<j)]);
                }
            }
        }
        cout<<d[(1<<n)-1]<<endl;
    }
}
