#include<bits/stdc++.h>
using namespace std;

int a[10009],b[10009];
void jizz(){cout<<0<<endl; exit(0);}
void move(int &a,int s){
    a+=s;
    while(a>9)a-=9;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int ans=0;
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
            if(a[i]<b[i]){
                int fix=b[i]-a[i];
                if(i+k>n)jizz();
                for(int j=0;j<k;++j){
                    move(a[i+j],fix);
                }
                ans+=fix;
                // cout<<fix<<endl;
            }
            else{
                a[i]-=9;
                int fix=b[i]-a[i];
                if(i+k>n)jizz();
                for(int j=0;j<k;++j){
                    move(a[i+j],fix);
                }
                ans+=fix;
            }
        }
    }
    cout<<ans<<endl;
}

