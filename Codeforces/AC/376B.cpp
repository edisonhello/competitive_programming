#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define PDE1(x) cout<<#x<<" : "<<x<<endl
#define PDE2(a,b) cout<<#a<<" : "<<a<<" , ", PDE1(b)
#define iosbase ios_base::sync_with_stdio(0); cin.tie(0);

void JIZZ(string s=""){cout<<s<<endl; exit(0);}

int mey[111];
int main(){
    iosbase;
    int n,m; cin>>n>>m;
    while(m--){
        int a,b,c; cin>>a>>b>>c;
        mey[a]+=c;
        mey[b]-=c;
    }
    int tot=0;
    for(int i=1;i<=n;++i)tot+=abs(mey[i]);
    cout<<tot/2<<endl;
}
