#include<bits/stdc++.h>

using namespace std;


inline int rit(){
    int t=0,key=1;
    char j;
    do{
            j=getchar();
            if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}

int main(){

    freopen("jizz","w",stdout);
    freopen("iiji","r",stdin);


    int m,n;
    while(scanf("%d %d",&m,&n) &&m &&n){
        int mtx[n][m];
        memset(mtx,0,sizeof(mtx));
        for(int i=0;i<m;i++){
            int t;
            t = rit();
            vector<int> pos;
            for(int j=0;j<t;j++){
                int tmp;
                tmp = rit();
                pos.push_back(tmp);
            }
            for(int j=0;j<t;j++){
                int tmp;
                tmp = rit();
                mtx[pos[j]-1][i] = tmp;
            }
        }

       /* for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",mtx[i][j]);
            }printf("\n");
        }*/

        printf("%d %d\n",n,m);
        for(int i=0;i<n;i++){
            queue<int> tmp;//tmp.clear();
            queue<int> val;//val.clear();
            for(int j=0;j<m;j++){
                if(mtx[i][j]!=0){
                    tmp.push(j);
                    val.push(mtx[i][j]);
                }
            }
            printf("%d",tmp.size());
            while(tmp.size()){
                printf(" %d",tmp.front()+1);
                tmp.pop();
            }printf("\n");
            bool fst=true;
            while(val.size()){
                if(!fst)printf(" ");
                fst=false;
                printf("%d",val.front());
                val.pop();
            }printf("\n");
        }
    }


}

