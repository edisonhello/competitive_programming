#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int a[100004];

int rec[3004][3004];

int get(int n,int k){
    for(int i=0;i<n;++i)a[i]=i;
    int cnt=0;
    do{
        int c=1;
        for(int i=1;i<n;++i)if(a[i]<a[i-1])++c;
        if(c==k)++cnt;
    }while(next_permutation(a,a+n));
    return cnt;
}

void init(){
    rec[1][1]=1;
    for(int i=2;i<=3000;++i){
        rec[i][1]=1;
        for(int j=2;j<=(i+1)/2;++j){
            rec[i][j]=(rec[i-1][j]*1ll*j%mod+rec[i-1][j-1]*1ll*(i+1-j)%mod)%mod;
        }
        for(int j=(i+1)/2+1;j<=i;++j){
            rec[i][j]=rec[i][i+1-j];
        }
    }
}

int main(){
    init();
    /* for(int i=1;i<=10;++i){
        for(int j=1;j<=i;++j){
            cout<<rec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; */
    int n,k; cin>>n>>k;
    /* for(int i=1;;++i){
        for(int j=1;j<=i;++j){
            cout<<get(i,j)<<" ";
            fflush(stdout);
        }
        cout<<endl;
    } */
    cout<<rec[n][k]<<endl;
}
