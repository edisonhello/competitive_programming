#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool us[222];
int a[222],lis[222],pos[222],len,used;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=1;
    for(;used<n;++ans){
        memset(lis,0,sizeof(lis));
        memset(pos,0,sizeof(pos));
        len=0;
        for(int i=0;i<n;++i){
            if(us[i])continue;
            auto it=lower_bound(lis,lis+len,a[i]);
            if(it==lis+len)++len;
            *it=a[i];
            pos[i]=it-lis;
        }
        for(int i=n-1,w=len-1;i>=0&&w>=0;--i){
            if(pos[i]==w){
                --w;
                us[i]=1;
                ++used;
            }
        }
    }
    cout<<(ans-1)<<endl;
}
