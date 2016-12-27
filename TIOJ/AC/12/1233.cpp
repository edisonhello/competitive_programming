#include<cstdio>
using namespace std;

char s[525][525];
bool v[525][525];

void dfs(int x,int y){
    v[x][y]=1;
    if(s[x][y-1]=='1' && !v[x][y-1])dfs(x,y-1);
    if(s[x+1][y-1]=='1' && !v[x+1][y-1])dfs(x+1,y-1);
    if(s[x+1][y]=='1' && !v[x+1][y])dfs(x+1,y);
    if(s[x+1][y+1]=='1' && !v[x+1][y+1])dfs(x+1,y+1);
    if(s[x][y+1]=='1' && !v[x][y+1])dfs(x,y+1);
    if(s[x-1][y+1]=='1' && !v[x-1][y+1])dfs(x-1,y+1);
    if(s[x-1][y]=='1' && !v[x-1][y])dfs(x-1,y);
    if(s[x-1][y-1]=='1' && !v[x-1][y-1])dfs(x-1,y-1);
}

int main(){
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i){
        scanf("%s",s[i]+1);
        s[i][0]=s[i][n+1]='0';
    }
    for(i=0;i<n+2;++i){
        s[0][i]=s[m+1][i]='0';
    }

    int ans=0;
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if(s[i][j]=='1' && !v[i][j]){
                dfs(i,j);
                ++ans;
            }
        }
    }
    if(ans==0)puts("0");
    else if(ans==1)puts("1");
    else if(ans==2)puts("2");
    else if(ans<=4)puts("3");
    else if(ans<=6)puts("4");
    else if(ans<=10)puts("5");
    else if(ans<=12)puts("6");
    else if(ans<=14)puts("7");
    else if(ans<=16)puts("8");
    else if(ans<=18)puts("9");
    else puts("10");
}
