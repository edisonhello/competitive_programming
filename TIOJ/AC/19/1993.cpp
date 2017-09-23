#include<cstdio>
#include<bitset>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int main(){
    int ts; scanf("%d",&ts); while(ts--){
        int n,h,mn=0,x,y,z; scanf("%d%d",&n,&h);
        bitset<100002> b; b[0]=1;
        while(n--){
            scanf("%d%d%d",&x,&y,&z);
            b=(b<<x)|(b<<y)|(b<<z);
            mn+=min(min(x,y),z);
        }
        if(mn>h)puts("no solution");
        else for(int i=h;i>=0;--i){
            if(b[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
}
