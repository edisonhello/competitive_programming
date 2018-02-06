#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const long long mod=10000;

#define int long long

int k,a[111],b[111];
int mat1[111][111],mat2[111][111],mat3[111][111];

void upans(){
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)mat3[i][j]=0;
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)for(int z=0;z<k;++z){
        mat3[i][j]+=mat2[i][z]*mat1[z][j]%mod;
    }
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)mat2[i][j]=mat3[i][j]%mod;
}
void upbase(){
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)mat3[i][j]=0;
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)for(int z=0;z<k;++z){
        mat3[i][j]+=mat1[i][z]*mat1[z][j]%mod;
    }
    for(int i=0;i<k;++i)for(int j=0;j<k;++j)mat1[i][j]=mat3[i][j]%mod;
}

void pow(int n){
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j)mat2[i][j]=0;
        mat2[i][i]=1;
    }
    while(n){
        if(n&1)upans();
        upbase(); n>>=1;
        /* for(int i=0;i<k;++i){
            for(int j=0;j<k;++j){
                cout<<mat1[i][j]<<" ";
            } cout<<endl;
        }
        for(int i=0;i<k;++i){
            for(int j=0;j<k;++j){
                cout<<mat2[i][j]<<" ";
            } cout<<endl;
        } */
        // cout<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>k,k){
    for(int i=0;i<k;++i)cin>>a[i];
    for(int i=1;i<=k;++i)cin>>b[i];
    cin>>n;
    // if(n<k){cout<<a[n]%mod<<'\n'; continue;}
    memset(mat1,0,sizeof(mat1));

    for(int i=0;i<k;++i)mat1[i][0]=b[i+1];
    for(int i=1;i<k;++i)mat1[i-1][i]=1;
    pow(n);
    /* for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            cout<<mat1[i][j]<<" ";
        } cout<<endl;
    } */
    int ans=0;
    for(int i=0;i<k;++i)ans+=a[k-i-1]*mat2[i][k-1]%mod;
    cout<<ans%mod<<'\n';
}}
