#include<iostream>
#include<algorithm>
#include<cstring>

int LIS[1005],pos[1005],a[1005];

int main(){
    int ts;cin>>ts;while(ts--){
        memset(LIS,0,sizeof(LIS));
        memset(pos,0,sizeof(pos));
        memset(a,0,sizeof(a));
        int n,len=0;cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
            int p=lower_bound(LIS,LIS+len,a[i])-LIS;
            pos[i]=p;
            LIS[p]=a[i];
            if(p==len)++len;
        }
        for(int i=len)
    }
}
