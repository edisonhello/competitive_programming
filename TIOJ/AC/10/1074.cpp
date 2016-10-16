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

bitset<5000> app;
int n,cnt;
ll tot,a[25],now;

int main(){
    while(scanf("%d",&n)!=EOF,n){
        cnt=0;
        tot=0;
        MS0(a);
        app.reset();
        for(int i=0;i<n;i++){
            a[i]=rit();
            tot+=a[i];
        }
        // cout<<tot<<" "<<n*(n+1)/2<<endl;
        if(tot>n*(n+1)/2 || tot==n){
            printf("NO\n");
            continue;
        }
        // PAR(a,n);
        for(int i=0;i<n;i++){
            now=0;
            for(int j=i;j<n;j++){
                now+=a[j];
                if(!app[now]){
                    // cout<<"get new! : "<<now<<endl;
                    app[now]=1;
                    ++cnt;
                    if((ll)cnt==tot)goto outfor;
                }
            }
        }
        outfor:;
        if((ll)cnt==tot){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
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
