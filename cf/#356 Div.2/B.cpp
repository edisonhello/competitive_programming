#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
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
int main(){
    int n=rit(),a=rit();a--;
    vint c;
    for(int i=0;i<n;i++){
        int t=rit();
        c.PB(t);
    }

    int get=0;
    for(int d=0;;d++){
        int l,r;
        l=a-d;
        r=a+d;
        if(d==0 && c[a]==1){
            get++;
        }
        else{
            if(l<0&&r>=n)break;
            if(l<0&&!(r>=n)&&c[r]==1){
                get++;
                continue;
            }
            if(!(l<0)&&(r>=n)&&c[l]==1){
                get++;
                continue;
            }
            if(!(l<0)&&!(r>=n)&&c[l]==1&&c[r]==1){
                get+=2;
                continue;
            }
        }
    }
    cout<<get<<endl;
}
