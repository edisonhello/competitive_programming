#include<bitset>
#include<cstdio>
using namespace std;

int n,i,j,cnt;
bitset<205> m[205];

int main(){
    for(i=1;i<=199;i++){
        m[i][100]=1;
        m[100][i]=1;
        m[i][i]=1;
        m[i][200-i]=1;
    }
    while(scanf("%d",&n)!=EOF){
        for(i=100-n+1;i<=100+n-1;i++){
            for(j=100-n+1,cnt=0;j<=100+n-1 && (i==100 || (i!=100 && cnt<3));j++){
                if(m[i][j]){
                    putchar('*');
                    cnt++;
                }
                else putchar(' ');
            }
            putchar('\n');
        }
    }
}
