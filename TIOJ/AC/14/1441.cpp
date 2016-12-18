#include<cstdio>

int main(){
    int n,ans=1,i,t,p;
    scanf("%d",&n);
    for(i=n,p=0;i;--i,p=t){
        scanf("%d",&t);
        if(ans&1){if(t<p)++ans;}
        else{if(t>p)++ans;}
    }
    if(!(ans&1))--ans;
    printf("%d\n",ans);
}
