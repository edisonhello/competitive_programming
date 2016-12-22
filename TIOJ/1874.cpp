#include<cstdio>
#include<bitset>
#include<vector>
// #include<iostream>
using namespace std;

short delby[10000008];
vector<int> prime;

void init(){
    for(int i=2;i<3200;++i){
        if(delby[i])continue;
        prime.push_back(i);
        for(int j=i*i;j<10000002;j+=i){
            delby[j]=i;
        }
    }
    // for(int i=1;i<50;++i)cout<<delby[i]<<" ";cout<<endl;
}

int main(){
    init();
    int ts;scanf("%d",&ts);while(ts--){
        int n;scanf("%d",&n);
        if(n==1){
            printf("1\n");
            continue;
        }
        if(!delby[n]){
            printf("2\n");
            continue;
        }
        int fstPme=delby[n],ans=1;
        {int t=1;while(n%fstPme==0){
            n/=fstPme;++t;
        }ans*=t;}
        for(int i=0,t;i<452;++i){
            if(n==1)break;
            if(n<prime[i])break;
            t=1;
            while(n%prime[i]==0){
                n/=prime[i];++t;
            }
            ans*=t;
        }
        if(n!=1)ans<<1;
        printf("%d\n",ans);
    }
}
