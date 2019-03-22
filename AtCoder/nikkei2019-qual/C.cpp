#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],o[100005],oa[100005],ob[100005];
bitset<100005> u;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
    long long ans=0;
    for(int i=1;i<=n;++i)oa[i]=i,ob[i]=i;
    sort(oa+1,oa+1+n,[&](const int &i,const int &j){ return a[i]+b[i]>a[j]+b[j]; });
    sort(ob+1,ob+1+n,[&](const int &i,const int &j){ return a[i]+b[i]>a[j]+b[j]; });
    long long aa=0,bb=0;
    int pa=1,pb=1;
    for(int i=1;i<=n;++i){
        if(i&1){
            while(u[oa[pa]])++pa;
            aa+=a[oa[pa]];
            u[oa[pa]]=1;
        }
        else{
            while(u[ob[pb]])++pb;
            bb+=b[ob[pb]];
            u[ob[pb]]=1;
        }
    }
    cout<<aa-bb<<endl;
}
