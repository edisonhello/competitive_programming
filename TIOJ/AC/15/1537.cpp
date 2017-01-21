#include<cstdio>
#define int char
int ans[25];

void dfs(int left,int lb,int dep){
    if(!left && dep>1){
        for(int i=0;i<dep;++i){
            if(i)printf(", %d",ans[i]);
            else printf("%d",ans[i]);
        }puts("");
        return;
    }
    if(lb>left)return;
    for(int i=lb;i<=left;++i){
        ans[dep]=i;
        dfs(left-i,i,dep+1);
    }
}

main(){
    int n,Pi=0;scanf("%*d");
    while(~scanf("%d",&n)){
        printf("Plank %d:\n",++Pi);
        dfs(n,1,0);
    }
}
