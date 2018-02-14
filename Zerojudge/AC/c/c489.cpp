#include<cstdio>
using namespace std;

int p1[1024],p2[1024],p3[1024];
int mem2[2],cnt2[2],mem2sz;

int main(){
    int n; scanf("%d",&n);
    while(n--){
        int t; scanf("%d",&t);
        if(mem2sz==0)mem2[mem2sz++]=t,++cnt2[0];
        else if(mem2sz==1 && t==mem2[0])++cnt2[0];
        else if(mem2sz==1)mem2[mem2sz++]=t,++cnt2[1];
        else if(t==mem2[0])++cnt2[0];
        else if(t==mem2[1])++cnt2[1];
        ++p1[t/1024/1024], ++p2[t/1024%1024], ++p3[t%1024];
    }
    int should=0;
    if(cnt2[0]!=cnt2[1]){
        if(cnt2[0]<cnt2[1])return printf("%d\n",mem2[0]),0;
        else return printf("%d\n",mem2[1]),0;
    }
    should=cnt2[0];
    int ans=0;
    for(int i=0;i<1024;++i){
        if(p1[i]%should)ans+=i*1024*1024;
        if(p2[i]%should)ans+=i*1024;
        if(p3[i]%should)ans+=i;
    }
    printf("%d\n",ans);
}
