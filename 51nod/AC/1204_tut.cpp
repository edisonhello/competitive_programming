#include<bits/stdc++.h>
using namespace std;

int djs[200005];

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n,q; cin>>n>>q; ++n;
    for(int i=1;i<200005;++i)djs[i]=i;
    for(int i=1;i<=q;++i){
        int l,r; cin>>l>>r;
        --l;
        string s; cin>>s;
        if(s[0]=='e'){
            if(C(l,r+n) || C(l+n,r))exit((cout<<i<<endl,0));
            U(l,r); U(l+n,r+n);
        }
        else{
            if(C(l+n,r+n) || C(l,r))exit((cout<<i<<endl,0));
            U(l+n,r); U(l,r+n);
        }
    }
    cout<<-1<<endl;
}
