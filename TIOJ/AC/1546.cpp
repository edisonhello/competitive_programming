#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define vint vector<int>
#define pii pair<int,int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

int n,m,p,q;
int mp[3003][3003];
ll act;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit(),m=rit(),p=rit(),q=rit();
    for(int i=0;i<m;i++){
        mp[0][i]=rit();
    }
    for(int i=1;i<m;i++){
        mp[i][0]=rit();
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<m;j++){
            mp[i][j]=mp[i-1][j-1]^mp[i][j-1]^mp[i-1][j];
        }
    }
    /*cout<<"map="<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d ",mp[i][j]);
        }
        putchar('\n');
    }*/
    act=(m-1)*(m-1);
    // printf("act=%d\n",act);
    int i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<m;j=k){
            for(k=j+1;k<m && mp[i][k]>=mp[i][k-1];k++){

            }
            int len=k-j;
            if(len>=p){
                // printf("in i=%d, %d %d\n",i,j,k);
                // printf("len=%d\n",len);
                if(len>=p && p==q){
                    act+=len-(p-1);
                    // printf("act+=%d\n",len-(p-1));
                }
                else if(len>=p && len<=q){
                    len-=(p-1);
                    act+=len*(len+1)/2;
                    // printf("act+=%d\n",len*(len+1)/2);
                }
                else{
                    int mlen=len-(p-1);
                    int xlen=len-(q-1);
                    act+=(mlen+xlen)*(mlen-xlen+1)/2;
                    // printf("act+=%d\n",(mlen+xlen)*(mlen-xlen+1)/2);
                }
            }
        }
    }
    // printf("act=%d\n",act);
    for(i=0;i<m;i++){
        for(j=0;j<m;j=k){
            for(k=j+1;k<m && mp[k][i]>=mp[k-1][i];k++){

            }
            int len=k-j;
            if(len>=p){
                // printf("in i=%d, %d %d\n",i,j,k);
                // printf("len=%d\n",len);
                if(len>=p && p==q){
                    act+=len-(p-1);
                    // printf("act+=%d\n",len-(p-1));
                }
                else if(len>=p && len<=q){
                    len-=(p-1);
                    act+=len*(len+1)/2;
                    // printf("act+=%d\n",len*(len+1)/2);
                }
                else{
                    int mlen=len-(p-1);
                    int xlen=len-(q-1);
                    act+=(mlen+xlen)*(mlen-xlen+1)/2;
                    // printf("act+=%d\n",(mlen+xlen)*(mlen-xlen+1)/2);
                }
            }
        }
    }

    // printf("act = %d\n",act);
    printf("%d\n",act%n);
}
