#include<bits/stdc++.h>
using namespace std;
struct C{int p,l;};
bool operator < (const C &a,const C &b){
    return a.p<b.p;
}
int main(){
    int ts;
    cin>>ts;
    while(ts--){
        int n,m;
        cin>>n>>m;
        vector<C> v;
        v.resize(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[i]={x,y};
        }
        sort(v.begin(),v.end());
        int cst=0;
        for(int i=0;i<n;i++){
            if(m>=v[i].l){
                cst+=v[i].l*v[i].p;
                m-=v[i].l;
            }
            else{
                cst+=m*v[i].p;
                m=0;
                break;
            }
        }
        if(m){
            cout<<"so sad\n";
        }
        else{
            cout<<cst<<'\n';
        }
    }
}
