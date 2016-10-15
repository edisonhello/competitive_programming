#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

int n,a[105],s,WAY[10005];
vint dp[10005];
vint better(vint ori,vint frm,int add,int nowW){
    int oriTot=0;
    for(int i:ori)oriTot+=i;
    assert(oriTot==0 || oriTot==nowW);
    frm.PB(a[add]);
    int newTot=0;
    for(int i:frm)newTot+=i;
    if(newTot!=nowW)return (vint)(0);
    if(S(ori)>S(frm))return ori;
    if(S(frm)>S(ori)){
        WAY[nowW]=S(frm)*(S(frm)-1)/2...? //BS
    }
    else{
        WAY[nowW]
        return frm;
    }
}
int main(){
    n=rit();
    for(int i=0;i<n;++i){
        a[i]=rit();
    }
    s=rit();
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int w=0;w<=s;w++){
            if(w<a[i])continue;
            dp[w]=better(dp[w],dp[w-a[i]],i,w);
        }
    }
    if(S(dp[w])){
        printf("%d %d\n",)
    }
    else printf("0 0\n");
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
