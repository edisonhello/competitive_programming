#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,i,zz,zzz,t;
char c;
vector<int> con[40005];
short gone[40005];
bool jizz;

int dfs(int now,int type){
    gone[now]=type;
    for(int j=0;j<con[now].size();j++){
        if(gone[con[now][j]]!=0){
            if(gone[con[now][j]]==type){
                return -1;
            }
        }
        else{
            if(dfs(con[now][j],-type)==-1){
                return -1;
            }
        }
    }
    return 1;
}

inline int rit(){
    t=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        for(i=0;i<n+3;i++){
            con[i].clear();
        }
        memset(gone,0,sizeof(gone));
        jizz=0;
        for(i=0;i<m;i++){
            zz=rit(),zzz=rit();
            con[zz].push_back(zzz);
            con[zzz].push_back(zz);
        }
        for(i=1;i<=n;i++){
            if(!gone[i]){
                if(dfs(1,111)==-1){
                    putchar_unlocked('N');
                    putchar_unlocked('o');
                    putchar_unlocked('\n');
                    jizz=1;
                    break;
                }
            }
        }
        if(!jizz){
            putchar_unlocked('Y');
            putchar_unlocked('e');
            putchar_unlocked('s');
            putchar_unlocked('\n');
        }
    }
}
