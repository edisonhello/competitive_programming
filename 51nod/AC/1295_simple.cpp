#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
using namespace std;

/* struct node{
    node *ch[2];
    int sz;
    node():sz(0){memset(ch,0,sizeof(ch));}
} *root; */

int a[65536];

int main(){
    int n,q; scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    do{
        int l,r,x; scanf("%d%d%d",&x,&l,&r); ++l,++r;
        int m0=0,m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,*p=a+l-1;
        int re=(r-l+1)&7,gr=(r-l+1)>>3;
        switch(re){
            case 7:m7=max(m7,x^*++p);
            case 6:m6=max(m6,x^*++p);
            case 5:m5=max(m5,x^*++p);
            case 4:m4=max(m4,x^*++p);
            case 3:m3=max(m3,x^*++p);
            case 2:m2=max(m2,x^*++p);
            case 1:m1=max(m1,x^*++p);
        }
        for(int i=0;i<gr;++i){
            m0=max(m0,x^*++p);
            m1=max(m1,x^*++p);
            m2=max(m2,x^*++p);
            m3=max(m3,x^*++p);
            m7=max(m7,x^*++p);
            m6=max(m6,x^*++p);
            m5=max(m5,x^*++p);
            m4=max(m4,x^*++p);
        }
        m0=max(m0,m1);
        m2=max(m2,m3);
        m4=max(m4,m5);
        m6=max(m6,m7);
        m0=max(m0,m2);
        m4=max(m4,m6);
        printf("%d\n",max(m0,m4));
    }while(--q);
}
