#include<bits/stdc++.h>
using namespace std;


int k,bel[566],lpw[566];

void get(int c){
    for(int d=0,j=c;d<k && j>0;++d,--j){
        if(bel[j]){
            if(lpw[j]>=d){
                for(int z=j+1;z<=c;++z){
                    bel[z]=bel[z-1];
                    lpw[z]=lpw[z-1]-1;
                }
            }
            else{
                bel[j+1]=j+1;
                lpw[j+1]=k-1;
                for(int z=j+2;z<=c;++z){
                    bel[z]=bel[z-1];
                    lpw[z]=lpw[z-1]-1;
                }
            }
            return;
        }
        else continue;
    }
    int mn=max(1,c-k+1);
    bel[mn]=mn;
    lpw[mn]=k-1;
    for(int z=mn+1;z<=c;++z){
        bel[z]=bel[z-1];
        lpw[z]=lpw[z-1]-1;
    }
}

int main(){
    int n; cin>>n>>k;
    for(int i=0;i<n;++i){
        int c; cin>>c; ++c;
        if(bel[c]){ cout<<bel[c]-1<<" "; continue; }
        get(c);
        cout<<bel[c]-1<<" ";
    }
}
