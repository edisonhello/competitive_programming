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

int main(){
    int ts=rit();while(ts--){
        int a=rit(),b=rit();
        printf("%d/%d = ",a,b);
        if(a%b==0){
            printf("%d\n",a/b);
            continue;
        }
        int left=0;
        while(1){
            printf("%d",a/b);
            a%=b;
            swap(a,b);
            if(!b){
                //
                while(left--){
                    printf("}");
                }
                printf("\n");
                break;
            }
            if(a%b==0){
                printf("+1/");
            }
            else{
                printf("+1/{");
                ++left;
            }
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
