#include<iostream>
#define ld long double
#include<algorithm>
#include<iomanip>
int n,nn[2];
ld a[100005];
using namespace std;
int main(){
    cin>>n>>nn[0]>>nn[1];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    sort(nn,nn+2);
    int ptr=0;
    ld cnt=0,ans=0;
    for(int i=0;i<nn[0];++i){
        cnt+=a[ptr++];
    }
    ans+=cnt/nn[0];
    cnt=0;
    for(int i=0;i<nn[1];++i){
        cnt+=a[ptr++];
    }
    ans+=cnt/nn[1];
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
