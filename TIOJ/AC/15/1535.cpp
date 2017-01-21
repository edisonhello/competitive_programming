#include<iostream>
#include<bitset>
using namespace std;

bitset<100000000> nP;
int ans[100000];

int rev(int i){
    int r=0;
    while(i){
        r=r*10+i%10;
        i/=10;
    }
    return r;
}

int main(){
    nP[1]=1;
    for(int i=1;i*i<100000000;++i){
        if(nP[i])continue;
        for(int j=i*i;j<100000000;j+=i){
            nP[j]=1;
        }
    }
    for(int i=1,revi,cnt=0;i<100000000;++i){
        if(nP[i])continue;
        revi=rev(i);
        if(nP[revi] || i==revi)continue;
        ans[cnt++]=i;
        if(cnt>=100000)break;
    }
    int ts,n;cin>>ts;while(ts--){
        cin>>n;cout<<ans[--n]<<endl;
    }
}
