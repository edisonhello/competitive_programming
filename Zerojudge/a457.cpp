#include<iostream>
using namespace std;

int n,m,s1[100005],s2[100005];
long long a[100005],b[100005],ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=n;i>0;--i){
        if(a[i]<b[i])s1[i]=s1[i+1]+1;
        else s1[i]=s1[i+1];
        if(a[i]>b[i])s2[i]=s2[i+1]+1;
        else s2[i]=s2[i+1];
    }
    for(int i=1;i<=n;++i){
        if(a[i]>b[i])ans+=s1[i];
        else if(a[i]<b[i])ans+=s2[i];
    }
    cout<<ans<<endl;
}
