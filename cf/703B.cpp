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

int c[100005];
int ka[100005];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit(),k=rit();
    int tot=0;
    for(int i=0;i<n;i++){
        c[i]=rit();
        tot+=c[i];
    }
    for(int i=0;i<k;i++){
        ka[i]=rit();
        ka[i]--;
    }

    int pnt=0;
    int lng=0;
    int rep=0;
    for(int i=0;i<n;i++){
        if(i==0){
            if(i==ka[pnt]){
                lng+=(tot-c[0])*c[0];
                lng+=(tot-c[0]-c[1]-c[n-1]-rep)*c[0];
                rep+=c[0];
                pnt++;
            }
            else{
                lng+=c[0]*c[1]+c[0]*c[n-1];
            }
        }
        else if(i==n-1){
            if(i==ka[pnt]){
                lng+=(tot-c[n-1])*c[n-1];
                lng+=(tot-c[n-1]-c[n-2]-c[0]-rep)*c[n-1];
                rep+=c[n-1];
                pnt++;
            }
            else{
                lng+=c[n-1]*c[n-2]+c[n-1]*c[0];
            }
        }
        else if(i==ka[pnt]){
            lng+=(tot-c[i])*c[i];
            lng+=(tot-c[i]-c[i-1]-c[i+1]-rep)*c[i];
            rep+=c[i];
            pnt++;
        }
        else{
            lng+=c[i]*c[i+1]+c[i]*c[i-1];
        }
        cout<<"after i="<<i<<" lng="<<lng<<endl;
    }
    cout<<lng/2<<endl;




}
