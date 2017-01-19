#include<cstdio>
#include<bitset>
using namespace std;

bitset<1005> b[1005];

int main(){
    int n,m,q,w,i;
    bool no;
    bitset<1005> now;
    while(~scanf("%d%d",&n,&m)){
        no=0;
        for(i=1;i<=n;++i)b[i].reset();
        do{
            scanf("%d%d",&q,&w);
            b[w][q]=1;
        }while(--m);
        now.reset();
        while(n--){
            scanf("%d",&q);
            if(((b[q]^now)&b[q]).any())no=1;
            now[q]=1;
        }
        if(no)puts("NO");
        else puts("YES");
    }
}
