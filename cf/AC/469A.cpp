#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<bool> cp;
    cp.resize(n);

    int p;cin>>p;
    for(int i=0;i<p;i++){
        int t;cin>>t;
        cp[t-1]=1;
    }
    cin>>p;
    for(int i=0;i<p;i++){
        int t;cin>>t;
        cp[t-1]=1;
    }

    for(int i=0;i<n;i++){
        if(cp[i]==0){
            cout<<"Oh, my keyboard!\n";
            return 0;
        }
    }
    cout<<"I become the guy.\n";
}
