#include<bits/stdc++.h>
using namespace std;

int a[100005],pos[100005];

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i]; a[i]%=k;
        if(a[i]==0){
            cout<<"1\n"<<i<<endl;
            exit(0);
        }
        a[i]+=a[i-1];
        a[i]%=k;
        if(pos[a[i]]){
            cout<<i-pos[a[i]]<<endl;
            for(int j=pos[a[i]]+1;j<=i;++j)cout<<j<<" ";
            cout<<endl;
            exit(0);
        }
        if(a[i]==0){
            cout<<i<<endl;
            for(int j=1;j<=i;++j)cout<<j<<" ";
            cout<<endl;
            exit(0);
        }
        pos[a[i]]=i;
    }
}
