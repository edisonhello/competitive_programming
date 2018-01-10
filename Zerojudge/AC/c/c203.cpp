// copy from UVa 13185
#include<bits/stdc++.h>
using namespace std;

int _(int x){
    int rt=1;
    for(int i=2;i<=x;++i){
        if(x%i==0){
            int p=1,b=1;
            while(x%i==0){
                x/=i;
                b*=i;
                p+=b;
            }
            rt*=p;
        }
    }
    return rt;
}

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        int c=_(n)-n;
        if(c==n)cout<<"perfect"<<endl;
        else if(c<n){
            cout<<"deficient"<<endl;
        }
        else cout<<"abundant"<<endl;
    }
}
