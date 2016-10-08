#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))


inline ll rit();
int n,h[4005];
ll ca[4005],dpa[4005][4005];


int main(){
    n=rit();
    for(int i=0;i<n;++i){
        ca[i]=rit();
        ca[i]+=ca[i-1];
    }
    for(int i=n-1;i>=0;--i){
        for(int j=i;j<n;++j){
            if(i==j){
                dpa[i][i]=ca[i]-ca[i-1];
                h[i]=i;
            }
            else{
                dpa[i][j]=(1ll<<60);
                int prv=h[j];
                for(int k=h[j-1];k<=prv;++k){
                    if(dpa[i][j]>dpa[i][k]+dpa[k+1][j]+ca[j]-ca[i-1]){
                        dpa[i][j]=dpa[i][k]+dpa[k+1][j]+ca[j]-ca[i-1];
                        h[j]=k;
                    }
                }
            }
        }
    }
    printf("%lld\n",dpa[0][n-1]-ca[n-1]);
}

ll rit_t,rit_k;
char rit_c;

inline ll rit(){
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
