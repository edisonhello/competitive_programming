#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int mod = 479001599;
int vec[250010];

inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }

bool solve2(int m) {
    int a, h1 = 0; // scanf("%d", &a);
    for (int i = 1; i < m; ++i) {
        scanf("%d", &a);
        h1 = add(a, mul(h1, 101));
    }
    int h2 = 0; scanf("%d", &a);scanf("%d", &a);
    for (int i = 1; i < m; ++i) {
        scanf("%d", &a);
        h2 = add(a, mul(h2, 101));
    }
    return h1 == h2;
}

bool solve3(int m) {
    int a, h1 = 0, bb; // scanf("%d", &a);
    for (int i = 1; i < m - 1; ++i) {
        scanf("%d", &a);
        h1 = add(a, mul(h1, 101));
    }
    int dd;
    int h2 = 0, h3 = 0; scanf("%d", &bb);scanf("%d", &a);scanf("%d", &dd);
    for (int i = 1; i < m - 1; ++i) {
        scanf("%d", &a);
        h2 = add(a, mul(h2, 101));
    }
    int cc, ee;
    scanf("%d", &cc); scanf("%d", &a); scanf("%d", &ee);
    for (int i = 1; i < m - 1; ++i) {
        scanf("%d", &a);
        h3 = add(a, mul(h3, 101));
    }
    return h1 == h2 && h2 == h3 && bb == cc && dd == ee;
}

bool solve4(int n,int m){
    bool ok=1;
    for(int i=1,tmp;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&tmp);
            if(i==1 || j==1)vec[j]=tmp;
            else if(vec[j]!=tmp)ok=0;
        }
        for(int j=m-1;j>=1;--j)vec[j+1]=vec[j];
    }
    return ok;
}

int main() {
    int t,n,m,i,j,tmp,mn,ii,jj; scanf("%d",&t);
    bool ok=1,okkkk;
    while (t--) {
        ok=1;
        scanf("%d%d",&n,&m);
        if(n==1 || m==1)okkkk=1;
        else okkkk=0;
        if (m <= 10) {solve4(n,m)?puts("Yes"):puts("No"); continue;}
        if (n == 2) {solve2(m)?puts("Yes"):puts("No"); continue;}
        if (n == 3) {solve3(m)?puts("Yes"):puts("No"); continue;}

        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                scanf("%d",&tmp);
                if(okkkk)continue;
                if(i==0){
                    vec[n-1+j]=tmp;
                }
                else if(j==0){
                    vec[n-i-1]=tmp;
                }
                else{
                    mn=min(i,j);
                    ii=i-mn,jj=j-mn;
                    if(ii==0){
                        if(tmp!=vec[n-1+jj])ok=0;
                    }
                    else if(tmp!=vec[n-ii-1])ok=0;
                }
            }
        }
        if(ok || okkkk)printf("Yes\n");
        else printf("No\n");
    }
}

