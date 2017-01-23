#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;
int pos[10005],a[10005],lis[10005],len;

int main(){
    cin>>n>>k;
    for(int i=0,t;i<n;++i){
        cin>>t;
        pos[t]=i;
    }
    while(k--){
        len=0;
        memset(lis,0,sizeof(lis));
        for(int i=0,t;i<n;++i){
            cin>>t;
            a[i]=pos[t];
            auto it=lower_bound(lis,lis+len,a[i]);
            if((it-lis)>=len)++len;
            *it=a[i];
        }
        cout<<len<<endl;
    }
}
