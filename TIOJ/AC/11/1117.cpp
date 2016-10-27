#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,a,b,l;
inline bool get(int &c){
    bool rt=1;
    int i,mlc=min(l,c);
    for(i=1;i<=mlc;i<<=1);
    while(i){
        i>>=1;
        if(i&l&c)rt^=1;
    }
    return rt;
}
int main(){
    while(scanf("%d%d%d%d",&n,&l,&a,&b)!=EOF){
        --l;
        for(int c=a-1;c<b;++c){
            if(c-a+1)putchar(' ');
            if(get(c)){
                putchar('-');
                putchar('1');
            }
            else{
                putchar('+');
                putchar('1');
            }
        }
        putchar('\n');
    }
}
