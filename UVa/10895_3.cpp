#include<bits/stdc++.h>
using namespace std;

struct pt{
    int m,n,v;
    pt(){
        m=n=v=0;
    }
};

bool operator < (const pt &a,const pt &b){
    if(a.n==b.n)return a.m<b.m;
    return a.n<b.n;
}

vector<pt> pts;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    bool fst=false;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF && m && n ){
        pts.clear();
        //if(fst)printf("\n");
        fst=true;
        printf("%d %d\n",n,m);
        for(int i=1;i<=m;i++){      //cout<<"jizz"<<endl;
            int cnt;
            scanf("%d",&cnt);
            vector<int> pos;
            for(int j=1;j<=cnt;j++){
                int tmp;
                scanf("%d",&tmp);
                pos.push_back(tmp);
            }
            for(int j=1;j<=cnt;j++){
                pt t;
                scanf("%d",&t.v);
                t.n=pos[j-1];
                t.m=i;
                pts.push_back(t);
            }
        }

        /*for(int asdf=0;asdf<pts.size();asdf++){
            printf("%d %d,%d\n",pts[asdf].m,pts[asdf].n,pts[asdf].v);
        }*/


        sort(pts.begin(),pts.end());

        int i,j,now=1;
        for(i=0;i<pts.size();i=j){
            vector<int> pos,val;
            /*if(pts[i].m!=now){
                printf("0\n\n");
                now++;
            }*/
            if(i==0){
                if(pts[0].m!=1){
                    for(int sdf=1;sdf<pts[0].m;sdf++){
                        printf("0\n\n");
                    }
                }
            }
            else{
                if(pts[i].m-pts[i-1].m>1){
                    for(int qwe=1;qwe<pts[i].m-pts[i-1].m;qwe++){
                        printf("0\n\n");
                    }
                }
            }
            for(j=i;pts[i].n==pts[j].n;j++){
                pos.push_back(pts[j].m/*?*/);
                val.push_back(pts[j].v);
            }
            printf("%d",j-i);
            for(int k=0;k<pos.size();k++){
                printf(" %d",pos[k]);
            }
            printf("\n");
            for(int k=0;k<val.size();k++){
                if(k)printf(" ");
                printf("%d",val[k]);
            }
            printf("\n");
        }


    }
}
