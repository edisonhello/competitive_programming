#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
ll a[1000005];
struct _{ll b,c;} b[1000005];
bool cmp(const _ &a,const _ &b){
    return a.b!=b.b?a.b<b.b:a.c<b.c;
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;++i)cin>>b[i].b>>b[i].c;
    sort(a,a+n);
    sort(b,b+m,cmp);
    int i=0,j=0;ll ans=0;
    while(i<n&&j<m){
        while(b[j].b<a[i]){
            ++j;
            if(j==m){
                cout<<"Impossible.\n";
                return 0;
            }
        }
        ans+=b[j].c;
        ++i,++j;
    }
    if(i==n)cout<<ans<<endl;
    else cout<<"Impossible.\n";
}
