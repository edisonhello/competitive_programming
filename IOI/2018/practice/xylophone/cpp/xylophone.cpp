#include "xylophone.h"
// #include<cstdio>
// #include <iostream>
// using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

static int a[5000];

void detect_pitch(int n) {
	/* int value = ask(0, N - 1);
	for(int i = 0; i < N; i++) {
		answer(i, i);
	} */
    /* int L=0,R=n-1;
    while(L>R){
        int M=(L+R)>>1;
        int z=ask(0,M);
        if(z==n-1)R=M;
        else L=M+1;
    }
    int r=L;
    L=0,R=r-1;
    while(L>R){
        int M=(L+R+1)>>1;
        int z=ask(M,r);
        if(z==n-1)L=M;
        else R=M-1;
    }
    int l=L; */
    /* int L=0,R=n-2;
    while(L<R){
        int M=(L+R+1)>>1;
        //cout<<"bs: "<<L<<" "<<R<<" "<<M<<endl;
        int z=ask(M,n-1);
        if(z==n-1)L=M;
        else R=M-1;
    }
    // cout<<"zero at "<<L<<endl;
    int l=L; */
    a[1]=ask(0,1);
    int l=0;
    // if(l>0)a[l-1]=ask(l-1,l);
    // if(l<n-1)a[l+1]=ask(l,l+1);
    /* for(int i=l-2;i>=0;--i){
        int a1=ask(i,i+1);
        if(a[i+1]-a1<0){ a[i]=a[i+1]+a1; continue; }
        if(a[i+1]+a1>=n){ a[i]=a[i+1]-a1; continue; }
        int a2=ask(i,i+2);
        if(a2==max(a[i+1],a[i+2])-min(a[i+1],a[i+2]))
            a[i]=a[i+1]+a1*(a[i+1]>a[i+2]?-1:1);
        else if(a1==a2)
            a[i]=a[i+1]+a1*(a[i+1]<a[i+2]?1:-1);
        else 
            a[i]=a[i+1]+a1*(a[i+1]<a[i+2]?-1:1);
    } */
    for(int i=l+2;i<n;++i){
        int a1=ask(i-1,i);
        // if(a[i-1]-a1<0){ a[i]=a[i-1]+a1; continue; }
        // if(a[i-1]+a1>=n){ a[i]=a[i-1]-a1; continue; }
        int a2=ask(i-2,i);
        if(a2==max(a[i-1],a[i-2])-min(a[i-1],a[i-2]))
            a[i]=a[i-1]+a1*(a[i-1]>a[i-2]?-1:1);
        else if(a1==a2)
            a[i]=a[i-1]+a1*(a[i-1]<a[i-2]?1:-1);
        else 
            a[i]=a[i-1]+a1*(a[i-1]<a[i-2]?-1:1);
    }
    int mn=n;
    for(int i=0;i<n;++i)mn=min(mn,a[i]);
    /* int upping=1,refr=l,preq=-1;
    for(int u=l-1;u>=0;--u){
        int az=ask(u,refr);
        if(az==preq){ preq=-1; ++u; upping^=1; refr=u; continue; }
        preq=az;
        if(upping)a[u]=a[refr]+az;
        else a[u]=a[refr]-az;
    }
    upping=1; preq=-1;
    int refl=l;
    for(int u=l+1;u<n;++u){
        int az=ask(refl,u);
        if(az==preq){ preq=-1; --u; upping^=1; refl=u; continue; }
        preq=az;
        if(upping)a[u]=a[refl]+az;
        else a[u]=a[refl]-az;
    } */
    for(int i=0;i<n;++i)a[i]-=mn;
    if([&]()->bool{for(int i=0;i<n;++i)if(a[i]==0)return 0;else if(a[i]==n-1)return 1;}())for(int i=0;i<n;++i)a[i]=n-1-a[i];
    // for(int i=0;i<n;++i)printf("a[%d]=%d\n",i,a[i]);
    for(int i=0;i<n;++i)answer(i,a[i]);
}
