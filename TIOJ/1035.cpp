#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int pcnt[10000010];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit();

    for(int i=2;i<10000001;i++){
        int f=0;
        for(int j=2;j<=(int)sqrt(i);j++){
            if(i%j==0){
                f=1;
                break;
            }
        }
        pcnt[i]=pcnt[i-1];
        if(!f){
            pcnt[i]++;
        }
    }
    // cout<<"a"<<endl;

    while(n--){
        int m=rit();
        printf("%d\n",pcnt[m]);
    }
}
