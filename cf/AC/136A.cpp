#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int g[n];

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        g[tmp-1]=i;
    }
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<g[i]+1;
    }
    cout<<endl;
}
