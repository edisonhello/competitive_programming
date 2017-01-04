#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int LIS[1005],pos[1005],a[1005],ans[1005];

int main(){
    int ts;cin>>ts;while(ts--){
        memset(LIS,0,sizeof(LIS));
        memset(pos,0,sizeof(pos));
        memset(ans,0,sizeof(ans));
        memset(a,0,sizeof(a));
        int n,len=0;cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
            int p=lower_bound(LIS,LIS+len,a[i])-LIS;
            pos[i]=p;
            LIS[p]=a[i];
            if(p==len)++len;
        }
        //for(int i=0;i<n;++i)cout<<pos[i]<<" ";cout<<endl;
        for(int i=n-1,t=len-1;i>=0;--i){
            if(pos[i]==t){
                ans[t]=a[i];
                --t;
            }
        }
        cout<<len<<endl;
        for(int i=0;i<len;++i){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
}
