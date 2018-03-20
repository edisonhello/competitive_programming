#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mat vector<vector<long long>>

#define set iiiiii

int m;
const ll mod=1000000007;

void open(mat &v){
    v.resize(m);
    for(int i=0;i<m;++i)v[i].resize(m);
}
void set(mat &v,int val=0){
    for(int i=0;i<m;++i)for(int j=0;j<m;++j)v[i][j]=val;
}
void setI(mat &v){
    set(v);
    for(int i=0;i<m;++i)v[i][i]=1;
}

mat operator*(const mat &a,const mat &b){
    mat rt; open(rt); set(rt);
    for(int i=0;i<m;++i)for(int j=0;j<m;++j)for(int k=0;k<m;++k)rt[i][j]=(rt[i][j]+a[i][k]*b[k][j])%mod;
    return rt;
}

mat pw(mat b,ll n){
    mat rt; open(rt); setI(rt);
    while(n){
        // cout<<"n: "<<n<<endl;
        if(n&1)rt=rt*b;
        b=b*b; n>>=1;
    } return rt;
}

int id[333];

int main(){
    ll n; int k; cin>>n>>m>>k;
    for(int i='a';i<='z';++i)id[i]=i-'a';
    for(int i='A';i<='Z';++i)id[i]=i-'A'+26;
    mat tr; open(tr); set(tr,1);
    while(k--){
        string s; cin>>s;
        tr[id[s[0]]][id[s[1]]]=0;
    }
    // cout<<"b4 pw"<<endl;
    tr=pw(tr,n-1);
    // cout<<"af pw"<<endl;
    ll tot=0;
    for(int i=0;i<m;++i)for(int j=0;j<m;++j)tot+=tr[i][j];
    cout<<tot%mod<<endl;
}
