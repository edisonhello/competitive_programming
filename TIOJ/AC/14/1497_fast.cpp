#include<cstdio>
using namespace std;

int x[200005],y[200005],r[200005],sa[200005],c[200005],t[200005];

void sort(int *a,int *x,int n,int m){
    // printf("n=%d, m=%d\n",n,m);
    // printf("x: ");
    // for(int i=0;i<n;++i)printf("%d ",x[i]); puts("");
    for(int i=0;i<=m;++i)c[i]=0;
    for(int i=0;i<n;++i)++c[x[a[i]]];
    for(int i=0;i<=m;++i)c[i+1]+=c[i];
    for(int i=n-1;i>=0;--i)t[--c[x[a[i]]]]=a[i];
    // printf("a: ");
    // for(int i=0;i<n;++i)printf("%d ",a[i]); puts("");
    for(int i=0;i<n;++i)a[i]=t[i];
    // printf("a: ");
    // for(int i=0;i<n;++i)printf("%d ",a[i]); puts("");
}

int main(){
    int n=0;
    while((x[n]=getchar())!=10)++n; x[n]=0;
    for(int i=0;i<n;++i)sa[i]=i;
    sort(sa,x,n,255);
    for(int d=1,nr;;d<<=1){
        r[sa[0]]=nr=1;
        for(int i=1;i<n;++i)r[sa[i]]=((x[sa[i]]!=x[sa[i-1]] || y[sa[i]]!=y[sa[i-1]])?++nr:nr);
        // printf("nr: %d\n",nr);
    // for(int i=0;i<n;++i)printf("%d ",sa[i]); puts("");
    // for(int i=0;i<n;++i)printf("%d ",x[i]); puts("");
    // for(int i=0;i<n;++i)printf("%d ",y[i]); puts("");
    // for(int i=0;i<n;++i)printf("%d ",r[i]); puts(""); puts("");
        if(nr==n)break;
        for(int i=0;i<n;++i)x[i]=r[i];
        for(int i=0;i<n;++i)y[i]=x[i+d];
    // for(int i=0;i<n;++i)cout<<sa[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<x[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<y[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<r[i]<<' '; cout<<endl; cout<<endl;
        sort(sa,y,n,nr);
    // for(int i=0;i<n;++i)cout<<sa[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<x[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<y[i]<<' '; cout<<endl;
    // for(int i=0;i<n;++i)cout<<r[i]<<' '; cout<<endl; cout<<endl;
        sort(sa,x,n,nr);
    }
    for(int i=0;i<n;++i)printf("%d\n",sa[i]);
}
