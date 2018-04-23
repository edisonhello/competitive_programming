#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,cnt=0; cin>>k>>n;
    if(k==0){
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                for(int k=0;j<19;++k){
                    if(k==i+j)continue;
                    cout<<i<<j<<k<<endl;
                    ++cnt;
                    if(cnt==n)exit(0);
                }
            }
        }
    }
    if(k==1){
        for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                cout<<i<<j<<i+j<<endl;
                ++cnt;
                if(cnt==n)exit(0);
            }
        }
    }
    if(k==2){
        for(int i=110;i<200;++i){
            cout<<11<<i<<i+11<<endl;
            ++cnt;
            if(cnt==n)exit(0);
        }
        for(int i=1111;;++i){
            cout<<111<<i<<111+i<<endl;
            ++cnt;
            if(cnt==n)exit(0);
        }
    }
}
