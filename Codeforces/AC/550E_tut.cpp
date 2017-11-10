#include<bits/stdc++.h>
using namespace std;

int a[100008];

void jizz(){cout<<"NO"<<endl; exit(0);}

int main(){
    int n; cin>>n; int now=0;
    string ans;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(i<n-2){
            ans+="(";
            ans+=(char)(a[i]+'0');
            ans+="->";
        }
        if(i==n-2){
            ans+=(char)(a[i]+'0');
            for(int ii=0;ii<n-2;++ii)ans+=")";
        }
        if(i==n-1){
            ans+="->";
            ans+=(char)(a[i]+'0');
        }
    }
    if(a[n-1]!=0)jizz();
    if(n==1)return cout<<"YES\n"<<ans.back()<<endl,0;
    int anss=a[n-2];
    for(int i=n-3;i>=0;--i){
        anss=!(anss==0 and a[i]==1);
    }
    if(!anss)jizz();
    cout<<"YES\n"<<ans<<endl;
}
