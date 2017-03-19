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
    int v=rit();
    int mxblks=-654;
    int nedv;
    for(int nv=v;nv>=0;nv--){
        int blks=0;
        int lftv=nv;
        while(lftv){
            double canptmxa_d = pow((double)lftv,(double)1/3);
            int canptmxa = (int)canptmxa_d;
            blks++;
            lftv-=(canptmxa*canptmxa*canptmxa);
        }
        if(blks>mxblks){
            mxblks=blks;
            nedv=nv;
        }
    }
    cout<<mxblks<<" "<<nedv<<endl;
}
