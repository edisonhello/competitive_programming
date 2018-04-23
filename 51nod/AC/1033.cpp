#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

#define mat vector<vector<long long>>

int nn;

void open(mat &m){
    m.resize(nn+2);
    for(int i=0;i<nn;++i)m[i]=vector<long long>(nn+2,0);
}

mat operator*(const mat &a,const mat &b){
    mat rt; open(rt);
    for(int i=0;i<nn;++i)for(int j=0;j<nn;++j)for(int k=0;k<nn;++k)(rt[i][j]+=a[i][k]*b[k][j])%=mod;
    return rt;
}

mat pw(mat b,int n){
    mat a; open(a); for(int i=0;i<nn;++i)a[i][i]=1;
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } return a;
}


int main(){
    int n,m; cin>>n>>m;
    nn=1<<n;
    mat tr; open(tr);
    for(int i=0;i<(1<<n);++i){
        for(int j=0;j<(1<<n);++j){
            if(i&j)continue;
            int x=i^j;
            x^=(1<<n)-1;
            for(int z=0;z<n-1;++z){
                if(((x&(3<<z))>>z)==3)x^=(3<<z),++z;
            }
            if(!x)tr[i][j]=1;
        }
    }
    /* for(int i=0;i<nn;++i){
        for(int j=0;j<nn;++j){
            cout<<tr[i][j]<<" ";
        }
        cout<<endl;
    } */
    tr=pw(tr,m);
    cout<<tr[0][0]<<endl;
}
