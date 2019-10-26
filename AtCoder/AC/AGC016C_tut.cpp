#include<bits/stdc++.h>
using namespace std;

int x[555][555];
int s[555];

int main(){
    int n,m,a,b; cin>>n>>m>>a>>b;
    if(n%a==0 && m%b==0)exit((cout<<"No"<<endl,0));
    cout<<"Yes"<<endl;
    if(m%b!=0){
        for(int i=1;i<=m;++i){
            if(i>=b){
                s[i]=s[i-b]-1;
            }
            else s[i]=10000;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<s[j]-s[j-1]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(int i=1;i<=n;++i){
            if(i>=a){
                s[i]=s[i-a]-1;
            }
            else s[i]=10000;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<s[i]-s[i-1]<<" ";
            }
            cout<<endl;
        }
    }
}
