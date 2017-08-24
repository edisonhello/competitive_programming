#include<bits/stdc++.h>
using namespace std;


inline int rit(){
    int t=0,k=1;char c;
    do{
        c = getchar();
        if(c=='-'){
            k=-1;
        }
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c = getchar();
    }while(c<='9'&&c>='0');
    return t*k;
}

int main(){
    int n=rit();


    int mxp,mnp;
    for(int i=0;i<n;i++){
        int t=rit();

        if(t==1){
            mnp=i;
        }
        if(t==n){
            mxp=i;
        }
    }
    cout<<max(max(mnp,mxp),max(n-mxp-1,n-mnp-1))<<endl;
}
