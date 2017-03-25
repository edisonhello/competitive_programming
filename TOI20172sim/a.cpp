#include<stdio.h>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
#define ll long long

bool SG[100000008];
int tak[22];
ll m;
int n;

inline int rit();
inline ll rll();

void bitfoc(){
    for(int i=tak[0];i<=m;++i){
        for(int j=0;j<n && i-tak[j]>=0;++j){
            if(SG[i-tak[j]]==0){
                SG[i]=1;
                break;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<=m;++i){
        if(SG[i])++cnt;
    }
    printf("%d\n",cnt);
}

#define int long long
bool tryLoop(int len){
    for(int i=1;i<=min(len*500,100000000ll);++i){
        if(SG[i]!=SG[i+len])return 0;
    }
    return 1;
}

void meow__(){
    for(int i=tak[0];i<=100000000;++i){
        for(int j=0;j<n && i-tak[j]>=0;++j){
            if(SG[i-tak[j]]==0){
                SG[i]=1;
                break;
            }
        }
    }
    int loop=1;
    for(;loop<=100000000;++loop){
        if(tryLoop(loop)){
            int loopin1=0,outloop=0;
            for(int j=1;j<=loop;++j)if(SG[j])loopin1++;
            int mPAloop=m%loop;
            for(int j=1;j<=mPAloop;++j)if(SG[j])++outloop;
            printf("%lld\n",m/loop*loopin1+outloop);
            break;
        }
    }
}
#undef int

int main(){
    m=rll(),n=rit(); // if(n>8)assert(1==0); // n<=10
    for(int i=0;i<n;++i)tak[i]=rit();
    sort(tak,tak+n);
    if(m<=100000000)bitfoc();
    else meow__();
}

inline int rit(){
    int x=0; char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        x=x*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return x;
}
inline ll rll(){
    ll x=0; char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        x=x*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return x;
}
