#include<cstdio>
using namespace std;


int main(){
    int ts; scanf("%d",&ts); while(ts--){
        int n,m; scanf("%d%d",&n,&m);
        int t;
        unsigned int h1=0,h2=0,h3=0;
        for(int i=1;i<m;++i){
            scanf("%d",&t);
            h1=(h1+t*848*i)^147965182;
        } scanf("%d",&t);
        // cout<<"h1: "<<h1<<endl;
        bool ok=1;
        for(int i=2;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",&t);
                if(j<m)h2=(h2+t*848*j)^147965182;
                if(j>1)h3=(h3+t*848*(j-1))^147965182;
            }
            // cout<<"h2,h3: "<<h2<<" "<<h3<<endl;
            if(h3!=h1){ ok=0; }
            h1=h2; h2=h3=0;
        }
        if(ok)puts("Yes");
        else puts("No");
    }
}
