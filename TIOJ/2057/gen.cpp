#include<bits/stdc++.h>
using namespace std;

int rand(int l,int r){
    return rand()%(r-l+1)+l;
}

int a[10022];
void sub1(){
    int p,k,n; p=k=rand(1,5); n=rand(2,100);
    cout<<p<<" "<<k<<" "<<n<<endl;
    int sum=k*n-p;
    for(int i=1;i<=p;++i)++a[i];
    while(sum--){
        ++a[rand(1,p)];
    }
    for(int i=1;i<=p;++i)cout<<a[i]<<" "; cout<<endl;
}
void sub2(){
    int p,k,n; p=k=rand(10,100); n=rand(2,10000);
    cout<<p<<" "<<k<<" "<<n<<endl;
    int sum=k*n-p;
    for(int i=1;i<=p;++i)++a[i];
    while(sum--){
        ++a[rand(1,p)];
    }
    for(int i=1;i<=p;++i)cout<<a[i]<<" "; cout<<endl;
}
void sub3(){
    int p,k,n; p=(k=(rand(0,5)?rand(6000,10000):rand(4,10)))+1; n=rand(2,10000);
    cout<<p<<" "<<k<<" "<<n<<endl;
    int sum=k*n-p;
    for(int i=1;i<=p;++i)++a[i];
    while(sum--){
        int pos=rand(1,p);
        ++a[pos];
    }
    for(int i=1;i<=p;++i)cout<<a[i]<<" "; cout<<endl;
}
void nosol(int p,int sum){
    while(sum--)++a[rand(1,p)];
}
void getans(int p,int k,int n){
    for(int i=0;i<k;++i){
        int it1=rand(1,n-1),it2=n-it1;
        a[rand(1,p)]+=it1;
        a[rand(1,p)]+=it2;
    }
}
void sub4(){
    int p,k,n; p=(k=rand(2,20))+2; n=rand(2,100000);
    cout<<p<<" "<<k<<" "<<n<<endl;
    int sum=k*n;
    bool sol=rand(0,6);
    while(1){
        if(sol)getans(p,k,n);
        else nosol(p,sum);
        bool ok=1;
        for(int i=1;i<=p;++i)if(a[i]==0)ok=0;
        if(ok)break;
        memset(a,0,sizeof(a));
    }
    for(int i=1;i<=p;++i)cout<<a[i]<<" "; cout<<endl;
}
void sub5(){
    int p,k,n; p=(k=(rand(0,1)?rand(24,40):40))+2; n=rand(2,100000);
    cout<<p<<" "<<k<<" "<<n<<endl;
    int sum=k*n;
    bool sol=rand(0,3);
    while(1){
        if(sol)getans(p,k,n);
        else nosol(p,sum);
        bool ok=1;
        for(int i=1;i<=p;++i)if(a[i]==0)ok=0;
        if(ok)break;
        memset(a,0,sizeof(a));
    }
    for(int i=1;i<=p;++i)cout<<a[i]<<" "; cout<<endl;
}
int main(){
    srand(clock());
    sub5();
}
