#include<bits/stdc++.h>
using namespace std;
int a[100009];
struct disjointSet{
    std::vector<int> djs;
    void init(int size){
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){djs[F(x)]=F(y);}
    bool C(int x,int y){return F(x)==F(y);}
} djs;
int main(){
    int n;while(cin>>n,n){
        int sz=n; djs.init(n+5);
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(djs.C(a[i],i))continue;
            djs.U(a[i],i); --sz;
        }
        if((n-sz)&1)cout<<"Marcelo\n";
        else cout<<"Carlos\n";
    }
}
