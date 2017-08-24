#include<bits/stdc++.h>
#define jizz using namespace std;int a[123];bool v[123];int main(){    int n; cin>>n;    for(int i=0;i<n;++i)cin>>a[i];    sort(a,a+n);    int ans=0;    while("jizz"){        int cnt=0;        for(int i=0;i<n;++i){            if(!v[i] && a[i]>=cnt){                ++cnt;                v[i]=1;            }        }        if(!cnt)break;        ++ans;    }    cout<<ans<<endl;}

jizz;
