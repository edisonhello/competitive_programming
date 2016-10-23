#include<bits/stdc++.h>
using namespace std;
string a[105];
int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        for(int i=0;i<n;++i)cin>>a[i];
        int mx=0;
        for(int i=0;i<n;++i){
            if(n-i<mx)break;
            for(int j=0;j<n;++j){
                if(n-j<mx)break;
                for(int nsz=0;i+nsz<n && j+nsz<n;++nsz){
                    if(a[i+nsz][j]=='N'&&a[i+nsz][j+nsz]=='N'){
                        for(int k=1;k<=nsz;++k){
                            if(a[i+nsz-k][j+nsz]!='N'){
                                goto jizzed;
                            }
                        }
                        mx=max(mx,nsz);
                        jizzed:;
                    }
                    else break;
                }
            }
        }
        mx-=2;
        if(mx<0)mx=0;
        cout<<mx<<'\n';
    }
}
