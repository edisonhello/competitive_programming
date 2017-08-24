#include<bits/stdc++.h>

inline int rit(){
    int a;scanf("%d",&a);return a;
}
inline char rch(){
    char a;do{a=getchar();}while(a<'A' || a>'z');return a;
}

char **map;
bool **go;
int m,n;

bool dfs(int i,int j,char key,int disi,int disj,int cf){
        //printf("gone %d %d, find %c, dist %d %d\t",i,j,key,disi,disj);
    go[i][j] = 1;//gone
    if(i==disi && j==disj){/*printf("circle\n");*/return 1;}//check
        //printf("keep finding\n");
    bool r1=0,r2=0,r3=0,r4=0;
    if(cf==1){
        if(j!=0&&map[i][j-1]==key&&go[i][j-1]==0)r2 = dfs(i,j-1,key,disi,disj,2);if(r2){return 1;}
        if(j!=n-1&&map[i][j+1]==key&&go[i][j+1]==0)r4 = dfs(i,j+1,key,disi,disj,4);if(r4){return 1;}
        if(i!=0&&map[i-1][j]==key&&go[i-1][j]==0)r1 = dfs(i-1,j,key,disi,disj,1);if(r1){return 1;}
    }
    else if(cf==2){
        if(i!=m-1&&map[i+1][j]==key&&go[i+1][j]==0)r3 = dfs(i+1,j,key,disi,disj,3);if(r3){return 1;}
        if(i!=0&&map[i-1][j]==key&&go[i-1][j]==0)r1 = dfs(i-1,j,key,disi,disj,1);if(r1){return 1;}
        if(j!=0&&map[i][j-1]==key&&go[i][j-1]==0)r2 = dfs(i,j-1,key,disi,disj,2);if(r2){return 1;}
    }
    else if(cf==3){
        if(j!=n-1&&map[i][j+1]==key&&go[i][j+1]==0)r4 = dfs(i,j+1,key,disi,disj,4);if(r4){return 1;}
        if(j!=0&&map[i][j-1]==key&&go[i][j-1]==0)r2 = dfs(i,j-1,key,disi,disj,2);if(r2){return 1;}
        if(i!=m-1&&map[i+1][j]==key&&go[i+1][j]==0)r3 = dfs(i+1,j,key,disi,disj,3);if(r3){return 1;}
    }
    else{
        if(i!=0&&map[i-1][j]==key&&go[i-1][j]==0)r1 = dfs(i-1,j,key,disi,disj,1);if(r1){return 1;}
        if(i!=m-1&&map[i+1][j]==key&&go[i+1][j]==0)r3 = dfs(i+1,j,key,disi,disj,3);if(r3){return 1;}
        if(j!=n-1&&map[i][j+1]==key&&go[i][j+1]==0)r4 = dfs(i,j+1,key,disi,disj,4);if(r4){return 1;}
    }
    //if(r1)printf("r1 ");
    //if(r2)printf("r2 ");
    //if(r3)printf("r3 ");
    //if(r4)printf("r4 ");
    if((r1||r2||r3||r4) == 0){
            //printf("back %d %d\n",i,j);
        go[i][j] = 0;
        return 0;
    }
    //printf("yo!");
    return 1;
}

int main(){
    m=rit();
    n=rit();

    map = new char*[m];
    go = new bool*[m];
    for(int i=0;i<m;i++){
        map[i] = new char[n];
        go[i] = new bool[n];
        for(int j=0;j<n;j++){
            map[i][j] = rch();
            go[i][j] = 0;
        }
    }
    bool r1,r2,r3,r4;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(go[i][j]==0){
                char key = map[i][j];
                r1 = r2 = r3 = r4 = 0;
                if(i!=0&&map[i-1][j]==key&&go[i-1][j]==0)r1 = dfs(i-1,j,key,i,j,1);
                else if(j!=0&&map[i][j-1]==key&&go[i][j-1]==0)r2 = dfs(i,j-1,key,i,j,2);
                else if(i!=m-1&&map[i+1][j]==key&&go[i+1][j]==0)r3 = dfs(i+1,j,key,i,j,3);
                else if(j!=n-1&&map[i][j+1]==key&&go[i][j+1]==0)r4 = dfs(i,j+1,key,i,j,4);
            }
            if(r1||r2||r3||r4){
                printf("Yes\n");
          //          if(r1)printf("r1 ");
    //if(r2)printf("r2 ");
    //if(r3)printf("r3 ");
    //if(r4)printf("r4 ");
                return 0;
            }
        }
    }
    printf("No\n");
}
