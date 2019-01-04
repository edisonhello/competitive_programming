#include<bits/stdc++.h>
using namespace std;

int sol1(int x){
    if(x<=90){
        x*=2;
    }
    else{
        x=180-x;
    }
    bool sol=0;
    for(int i=3;i<=10000;++i){
        double z=double(360)/i;
        if(abs(round(z)-z)>1e-6)continue;
        int zz=round(z);
        // cout<<"i: "<<i<<" , zz: "<<zz<<endl;
        if(x%zz==0){
            return i;
        }
    }
    return -1;
}

int mp[1000];

int sol2(int x){
    return mp[x];
}

int main(){
    for(int i=360;i>=3;--i){
        for(int j=2;j<i;++j){
            for(int k=j+1;k<=i;++k){

                double ag=(double(180))/i;
                double aa=((i+1)-k)*ag;
                if(abs(aa-round(aa))>1e-8)continue;
                // if(round(aa)==91)cout<<"91: "<<i<<" "<<j<<" "<<k<<endl;
                mp[int(round(aa))]=i;
            }
        }
    }
    int t; cin>>t; while(t--){
        int x; cin>>x; 
        int a1=sol1(x);
        int a2=sol2(x);
        // cout<<x<<" "<<a1<<" "<<a2<<endl;
        // assert(a1==a2);
        cout<<a2<<endl;
    }
}
