#include<bits/stdc++.h>
using namespace std;


int n,c[300005];

int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>c[i];
    int l=0,r=n+1;
    while(r-l>1){
        int m=(r+l)/2;
        cout <<"first m = "<<m<<endl;
        bool ok=0;
        for(int i=0;i<n;++i){
            if(i+m-1>n-1)break;
            if(c[i]!=c[i+m-1]){
                ok=1;
                break;
            }
        }
        cout<<"ok: "<<ok<<endl;
        if(ok)l=m;
        else r=m;
    }
    cout<<l-1<<endl;
}

