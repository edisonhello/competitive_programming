#include<bits/stdc++.h>
using namespace std;


int bel[566];

int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i){
        int c; cin>>c; ++c;
        if(bel[c]){ cout<<bel[c]-1<<" "; continue; }
    }
}
