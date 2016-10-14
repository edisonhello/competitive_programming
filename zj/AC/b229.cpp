#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

unsigned ll dp[55][109][55][3]; //mid=55

int main(){
    int n;
    cin>>n;
    dp[1][55-1][1][0]=dp[1][55][2][1]=dp[1][55+1][1][2]=1;
    unsigned ll cnt=0;
    if(n==1){
        cout<<3<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<54;j++){
            for(int k=1;k<=53;k++){
                dp[i][55+j][k][0]=dp[i-1][55+j+1][k][0]+dp[i-1][55+j+1][k][1];
                dp[i][55+j][k][1]=dp[i-1][55+j][k-1][0]+dp[i-1][55+j][k-1][1]+dp[i-1][55+j][k-1][2];
                dp[i][55+j][k][2]=dp[i-1][55+j-1][k][1]+dp[i-1][55+j-1][k][2];
                dp[i][55-j][k][0]=dp[i-1][55-j+1][k][0]+dp[i-1][55-j+1][k][1];
                dp[i][55-j][k][1]=dp[i-1][55-j][k-1][0]+dp[i-1][55-j][k-1][1]+dp[i-1][55-j][k-1][2];
                dp[i][55-j][k][2]=dp[i-1][55-j-1][k][1]+dp[i-1][55-j-1][k][2];
                if(i==n){
                    cnt+=dp[i][55+j][k][0]+dp[i][55+j][k][1]+dp[i][55+j][k][2];
                    if(j){
                        cnt+=dp[i][55-j][k][0]+dp[i][55-j][k][1]+dp[i][55-j][k][2];
                    }
                    // if(j<5 && k<5)cout<<j<<" "<<k<<" "<<cnt<<endl;
                }
            }
        }
    }
    cout<<cnt<<endl;
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
