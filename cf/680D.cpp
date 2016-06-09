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
/*inline ull rit(){
    ull t=0;int k=1;
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
}*/
int main(){
    ull v;cin>>v;
    int mxblks=-654;
    int nedv;
    long double mxcanptmxa_d = pow((long double)v,(long double)1/3);
    int mxcanptmxa = (int)mxcanptmxa_d;
    for(int nv=v;nv>=0;nv--){
        long double nvcanptmxa_d = pow((long double)nv,(long double)1/3);
        int nvcanptmxa = (int)nvcanptmxa_d;
        if(mxcanptmxa-nvcanptmxa>1){
            break;
        }
        int blks=0;
        ull lftv=nv;
        // cout<<"try "<<nv<<"\n";
        int cnt=0;
        while(lftv){
            long double canptmxa_d = pow((long double)lftv,(long double)1/3);
            int canptmxa = (int)(canptmxa_d);
            if(canptmxa==nvcanptmxa){
                cnt++;
            }
            blks++;
            lftv-=(canptmxa*canptmxa*canptmxa);
        }
        if(cnt==1 && mxcanptmxa-nvcanptmxa>1){
            break;
        }
        if(blks>mxblks){
            mxblks=blks;
            nedv=nv;
        }
    }
    cout<<mxblks<<" "<<nedv<<endl;
}
