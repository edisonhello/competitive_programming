#include<iostream>
#include<map>
using namespace std;

int djs[400055];
int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}
map<string,int> mp;

int main(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;++i){
        string s;cin>>s;mp[s]=i;
        djs[i]=i;
        djs[i+n]=i+n;
    }
    while(m--){
        int c;string s,t;cin>>c>>s>>t;int a=mp[s],b=mp[t];
        if(c==1){
            if(C(a+n,b)||C(a,b+n))cout<<"NO"<<endl;
            else{
                U(a,b);U(a+n,b+n);cout<<"YES"<<endl;
            }
        }
        else{
            if(C(a,b)||C(a+n,b+n))cout<<"NO"<<endl;
            else{
                U(a,b+n);U(a+n,b);cout<<"YES"<<endl;
            }
        }
    }
    while(q--){
        string s,t;cin>>s>>t;int a=mp[s],b=mp[t];
        if(C(a,b)||C(a+n,b+n))cout<<1<<endl;
        else if(C(a,b+n)||C(a+n,b))cout<<2<<endl;
        else cout<<3<<endl;
    }
}
