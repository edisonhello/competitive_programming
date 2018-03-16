#include<bits/stdc++.h>
using namespace std;

int n,a[50005];

int main(){
    cin>>n;
    int tot=0,mx=0;
    for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
    for(int i=1,j=1,len=a[1];i<=n;){
        auto dis=[&]()->int{return min(len,tot-len);};
        auto udis=[&](){mx=max(mx,dis());};
        udis();
        while(1){
            int jj=j+1; if(jj>n)jj-=n;
            int rdis=dis();
            udis();
            len+=a[jj];
            // cout<<i<<" "<<j<<" "<<rdis<<" "<<dis()<<endl;
            if(dis()<rdis){
                len-=a[jj];
                break;
            }
            j=jj;
        }
        len-=a[i]; ++i;
        udis();
    }
    cout<<mx<<endl;
}
