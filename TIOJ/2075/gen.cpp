#include<bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0)+clock());
    if(false){ // 0,1,2,3
        int n=1024,k=1024;
        cout<<n<<" "<<k<<endl;
        for(int i=1;i<=n;++i)cout<<rand()%1048576<<" ";
        cout<<endl;
    }
    if(false){ // 4,5,6,7
        int n=1024-rand()%10,k=1024-rand()%10;
        cout<<n<<" "<<k<<endl;
        for(int i=1;i<=n;++i)cout<<rand()%1048576<<" ";
        cout<<endl;
    }
    if(false){ // 8
        int n=1024,k=1024;
        cout<<n<<" "<<k<<endl;
        for(int i=1;i<=n;++i){
            if(i&1)cout<<1048575<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    if(false){ // 9
        int n=1024,k=512;
        cout<<n<<" "<<k<<endl;
        for(int i=1;i<=n;++i){
            if(i&1)cout<<1048575<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    if(false){ // 10
        int n=1024,k=0;
        cout<<n<<" "<<k<<endl;
        for(int i=0;i<n;++i)cout<<rand()%1048576<<" ";
        cout<<endl;
    }
    if(false){ // 11
        int n=1024,k=0;
        cout<<n<<" "<<k<<endl;
        for(int i=0;i<n;++i)cout<<0<<" ";
        cout<<endl;
    }
    if(true){ // 12
        int n=1024,k=455;
        cout<<n<<" "<<k<<endl;
        for(int i=0;i<n;++i)cout<<0<<" ";
        cout<<endl;

    }
}
