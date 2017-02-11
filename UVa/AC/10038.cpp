#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool app[3005];
#define int long long
main(){
    // freopen("out","w",stdout);
    // freopen("in","r",stdin);
    int n;while(cin>>n){
        memset(app,0,sizeof(app));
        bool ans=1;
        for(int i=0,prv,t;i<n;++i){
            if(!i){
                cin>>prv;
            }
            else{
                cin>>t;
                if(abs(t-prv)>=n || app[abs(t-prv)])ans=0;
                else app[abs(t-prv)]=1;
                prv=t;
            }
        }
        if(ans)cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }
}
