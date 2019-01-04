#include<bits/stdc++.h>
using namespace std;

int rec[150005];

bool broke;
int ask(int x){
    if(rec[x]==-1){
        if(broke){
            broke=0;
            printf("2\n");
        }
        printf("1 %d\n",x);
        fflush(stdout);
        int y; cin>>y;
        rec[x]=y;
        if(y)broke=1;
    }
    return rec[x];
}

int main(){
    memset(rec,-1,150005<<2);
    int n,c; scanf("%d%d",&n,&c);
    int L=1,R=n;
    while(L<R){
        int distance=(R-L+1);
        if(distance<c){
            break;
        }
        int step=distance/c;
        bool up=0;
        int last=0;
        for(int x=L-1+step;x<=R;x+=step){
            if(ask(x)){
                tie(L,R)=make_pair(x-step+1,x);
                up=1;
                break;
            }
            last=x;
        }
        if(!up){
            tie(L,R)=make_pair(last+1,R);
        }
    }
    for(int i=L;i<=R;++i){
        if(ask(i)){
            printf("3 %d\n",i);
            exit(0);
        }
    }
}
