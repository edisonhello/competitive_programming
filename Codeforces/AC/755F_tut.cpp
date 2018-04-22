#pragma GCC optimize("Ofast")
#include<bitset>
#include<vector>
#include<cstdio>
using namespace std;

int a[1000006];
bitset<1000006> v,can;

int main(){
    int n,k; scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    vector<int> szs;
    for(int i=1;i<=n;++i){
        if(v[i])continue;
        szs.push_back(1);
        v[i]=1;
        int j=a[i];
        while(j!=i){
            v[j]=1;
            ++szs.back();
            j=a[j];
        }
    }
    [&](){
        can[0]=1;
        vector<int> big,small(1005,0);
        for(int i:szs){
            if(i<=1000)++small[i];
            else big.push_back(i);
        }
        for(int i:big)can|=can<<i;
        for(int i=1,j;i<=1000;++i){
            for(j=0;(1<<j)<=small[i];++j){
                can|=can<<(i*(1<<j));
                small[i]-=(1<<j);
            }
            can|=can<<(i*(small[i]));
        }
        if(can[k])printf("%d ",k);
        else printf("%d ",k+1);
    }();
    [&,k]()mutable{
        int c[5]={0};
        for(int i:szs){
            while(i>1){
                i-=2;
                ++c[2];
            }
            if(i)++c[1];
        }
        int ans=0;
        if(c[2]<k){
            ans+=c[2]*2;
            k-=c[2];
            if(c[1]<k)ans+=c[1];
            else ans+=k;
        }
        else ans+=k*2;
        printf("%d",ans);
    }();
}
