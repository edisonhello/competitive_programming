#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    int n; cin>>n;
    int tot=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        tot+=a[i];
    }
    tot=(tot+1)/2;
    for(int i=1;i<=n;++i){
        tot-=a[i];
        if(tot<=0){
            cout<<i;
            exit(0);
        }
    }
}
