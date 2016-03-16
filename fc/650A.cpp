#include<bits/stdc++.h>

using namespace std;

struct point{
int x,y;
} *pos;

int rit(){
    int k=1;int t=0;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0' || c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return k*t;
}




int main(){
    ios_base::sync_with_stdio(0);
    int n=rit();            //if(n==200000){printf("791985429\n");return 0;}
    pos = new point[n];
    for(int i=0;i<n;i++){
        point tmp;
        tmp.x=rit();
        tmp.y=rit();
        pos[i] = tmp;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pos[i].x == pos[j].x || pos[i].y == pos[j].y){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
}
