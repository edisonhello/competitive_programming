#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

short vec[500006];
char stk[20];

char gchar(){
    const int N=1048576;
    static char buf[N];
    static char *p=buf,*end=buf;
    if(p==end){
        if((end=buf+fread(buf,1,N,stdin))==buf)return -1;
        p=buf;
    } return *p++;
}

int rit(){
    char c=0; bool flag=0; int x=0;
    while(c=gchar(stdin),(c<'0'&&c!='-')||c>'9');
    c=='-'?(flag=1,x=0):(x=c-'0');
    while(c=gchar(stdin),c>='0'&&c<='9')x=x*10+c-'0';
    if(flag)x=-x;
    return x;
}

int main() {
    int t,n,m,i,j,tmp,mn,ii,jj; t=rit();
    short stmp,ptr;
    bool ok=1,okkkk;
    while (t--) {
        ok=1;
        n=rit(),m=rit();
        if(n==1 || m==1)okkkk=1;
        else okkkk=0;
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                tmp=rit();
                stmp=tmp/32768;
                if(okkkk)continue;
                if(i==0){
                    vec[n-1+j]=stmp;
                }
                else if(j==0){
                    vec[n-i-1]=stmp;
                }
                else{
                    mn=min(i,j);
                    ii=i-mn,jj=j-mn;
                    if(ii==0){
                        if(stmp!=vec[n-1+jj])ok=0;
                    }
                    else if(stmp!=vec[n-ii-1])ok=0;
                }
                ptr=-1;
                while(tmp){
                    stk[++ptr]=tmp%10+'0';
                    tmp/=10;
                }
                while(ptr>0){
                    ungetc(stk[--ptr],stdin);
                }
                ungetc(' ',stdin);
            }
        }
        printf("meow");
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                tmp=rit();
                stmp=tmp%32768;
                if(okkkk)continue;
                if(i==0){
                    vec[n-1+j]=stmp;
                }
                else if(j==0){
                    vec[n-i-1]=stmp;
                }
                else{
                    mn=min(i,j);
                    ii=i-mn,jj=j-mn;
                    if(ii==0){
                        if(stmp!=vec[n-1+jj])ok=0;
                    }
                    else if(stmp!=vec[n-ii-1])ok=0;
                }
            }
        }
        if(ok || okkkk)printf("Yes\n");
        else printf("No\n");
    }
}
