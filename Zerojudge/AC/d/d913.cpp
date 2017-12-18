#include<bits/stdc++.h>
using namespace std;

int a[6][7];
int main(){
    for(int i=0;i<6;++i){
        for(int j=0;j<7;++j){
            cin>>a[i][j];
        }
    }
    int d[6]={1,2,3,4,5,6};
    do{
        bool ok=1;;
        for(int i=0;i<6;++i){
            int cnt=0;
            for(int j=0;j<6;++j){
                if(d[j]==a[i][j])++cnt;
            }
            if(cnt!=a[i][6]){ok=0; break;}
        }
        if(ok)return printf("%d %d %d %d %d %d\n",d[0],d[1],d[2],d[3],d[4],d[5]),0;
    }while(next_permutation(d,d+6));
}
