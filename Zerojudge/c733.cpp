#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")

#define ASDF fre##ad_unlocked

#include<cstdio>
#include<algorithm>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+ASDF(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}
#pragma GCC diagnostic pop

int a[2097152];
int main(){
    int n,m,x; rit(n,m,x);
    for(int i=1;i<=n;++i)a[i]=1;
    while(m--){
        int c,u,v,k; rit(c,u,v);
        int r=(v-u+1)&7,q=(v-u+1)>>3,d=v-u+1;
        int *p=a+u;
        switch(c){
            case 1: {
                rit(k);
                while(d--)*p=(*p+k>x?*p+k-x:*p+k),++p;
                /* while(r--)a[u]=(a[u]+k>x?a[u]+k-x:a[u]+k), ++u;
                int i0=u++,i1=u++,i2=u++,i3=u++;
                int i4=u++,i5=u++,i6=u++,i7=u++;
                while(q--){
                    a[i0]=(a[i0]+k>x?a[i0]+k-x:a[i0]+k), i0+=8;
                    a[i1]=(a[i1]+k>x?a[i1]+k-x:a[i1]+k), i1+=8;
                    a[i2]=(a[i2]+k>x?a[i2]+k-x:a[i2]+k), i2+=8;
                    a[i3]=(a[i3]+k>x?a[i3]+k-x:a[i3]+k), i3+=8;
                    a[i4]=(a[i4]+k>x?a[i4]+k-x:a[i4]+k), i4+=8;
                    a[i5]=(a[i5]+k>x?a[i5]+k-x:a[i5]+k), i5+=8;
                    a[i6]=(a[i6]+k>x?a[i6]+k-x:a[i6]+k), i6+=8;
                    a[i7]=(a[i7]+k>x?a[i7]+k-x:a[i7]+k), i7+=8;
                } */
            } break;
            case 2: {
                rit(k);
                while(d--)*p++=k;
                /* while(r--)a[u++]=k;
                int i0=u++,i1=u++,i2=u++,i3=u++;
                int i4=u++,i5=u++,i6=u++,i7=u++;
                while(q--){
                    a[i0]=k, i0+=8;
                    a[i1]=k, i1+=8;
                    a[i2]=k, i2+=8;
                    a[i3]=k, i3+=8;
                    a[i4]=k, i4+=8;
                    a[i5]=k, i5+=8;
                    a[i6]=k, i6+=8;
                    a[i7]=k, i7+=8;
                } */
            } break;
            case 3: {
                rit(k);
                int z=0;
                while(d--)z+=(*p++<=k);
                printf("%d\n",z);
                /* int z=0,z0=0,z1=0,z2=0,z3=0,z4=0,z5=0,z6=0,z7=0;
                while(r--)z+=(a[u++]<=k);
                int i0=u++,i1=u++,i2=u++,i3=u++;
                int i4=u++,i5=u++,i6=u++,i7=u++;
                while(q--){
                    z0+=(a[i0]<=k), i0+=8;
                    z1+=(a[i1]<=k), i1+=8;
                    z2+=(a[i2]<=k), i2+=8;
                    z3+=(a[i3]<=k), i3+=8;
                    z4+=(a[i4]<=k), i4+=8;
                    z5+=(a[i5]<=k), i5+=8;
                    z6+=(a[i6]<=k), i6+=8;
                    z7+=(a[i7]<=k), i7+=8;
                }
                printf("%d\n",z+z0+z1+z2+z3+z4+z5+z6+z7); */
            } break;
            case 4: {
                long long z=0;
                while(d--)z+=*p++;
                printf("%lld\n",z);
                /* long long z=0,z0=0,z1=0,z2=0,z3=0,z4=0,z5=0,z6=0,z7=0;
                while(r--)z+=a[u++];
                int i0=u++,i1=u++,i2=u++,i3=u++;
                int i4=u++,i5=u++,i6=u++,i7=u++;
                while(q--){
                    z0+=a[i0], i0+=8;
                    z1+=a[i1], i1+=8;
                    z2+=a[i2], i2+=8;
                    z3+=a[i3], i3+=8;
                    z4+=a[i4], i4+=8;
                    z5+=a[i5], i5+=8;
                    z6+=a[i6], i6+=8;
                    z7+=a[i7], i7+=8;
                }
                printf("%lld\n",z+z0+z1+z2+z3+z4+z5+z6+z7); */
            } break;
        }
    }
}
