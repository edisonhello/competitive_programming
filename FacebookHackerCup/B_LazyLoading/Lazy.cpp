#include<iostream>
#include<algorithm>
using namespace std;

int a[105];

int main(){
    freopen("lazy_loading.txt","r",stdin);
    freopen("lazy_loading.out","w",stdout);
    int ts;cin>>ts;for(int c=1;c<=ts;++c){
        cout<<"Case #"<<c<<": ";
        int n;cin>>n;
        for(int i=0;i<n;++i)cin>>a[i];
        sort(a,a+n);
        int ans=0;
        int l=0,r=n-1;
        while(++ans){
            int nitem=(49/a[r])+1;
            if(a[r]>=50)--nitem;
            l+=nitem;--r;
            if(l>r)break;
        }
        cout<<ans<<endl;
    }
}
