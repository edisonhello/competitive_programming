#include<bits/stdc++.h>
using namespace std;

int a[200005],djs[200005],now[200005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],djs[i]=i;
    djs[n+1]=n+1;
    int q; cin>>q; while(q--){
        int c; cin>>c;
        if(c==1){
            int p,x; cin>>p>>x;
            p=F(p);
            while(p<=n && x>0){
                if(a[p]-now[p]>x){
                    now[p]+=x;
                    x=0;
                }
                else{
                    x-=a[p]-now[p];
                    now[p]=a[p];
                    djs[p]=p+1;
                    ++p;
                }
            }
        }
        else{
            int x; cin>>x;
            cout<<now[x]<<'\n';
        }
    }
}
