#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> ans(4);

main(){
    int v; cin>>v; ans[0]=9000000000ll;
    for(int i=(int)(ceil(pow(v,1./3)));i>=1;--i){
        if(v%i==0){
            for(int j=(int)(ceil(pow(v/i,0.5)));j>=1;--j){
                if(v/i%j==0){
                    int a[]={2*(i*j+(i+j)*(v/i/j)),i,j,v/i/j}; sort(a+1,a+4);
                    vector<int> va(a,a+4); ans=min(ans,va);
                }
            }
        }
    }
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
