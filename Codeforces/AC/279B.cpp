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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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
};

int n,t,a[100005];

int main(){
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int s=0,e=0;
    int nt=0;
    int tot=0;
    int mx=-99;
    while(s<n){
        while(nt+a[s]<=t && s<n){
            nt+=a[s];
            s++;
            tot++;
        }
        // cout<<mx<<endl;
        mx=max(mx,tot);
        nt-=a[e];
        e++;
        tot--;
    }
    cout<<mx<<endl;
}



/*#include<bits/stdc++.h>
using namespace std;
int b,t,*a;
bool *c;
int main(){
    cin>>b>>t;
    a = new int[b];
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    c = new bool[b];
    memset(c,1,sizeof(c));

    int i,j=0,mx=0,now=0;
    for(i=0,j=0;i<b;i++){
        for(;j<b;j++){
            if(c[j])now+=a[j];
            c[j]=0;
            if(now>t){  //cout<<"i"<<i<<" j"<<j<<"jizz now"<<now<<endl;
                break;
            }

            mx=max(mx,j-i+1);   //cout<<"i"<<i<<" j"<<j<<" now"<<now<<endl;
        }
        now-=a[i];  //cout<<"--- a[i]"<<a[i]<<"now now"<<now<<endl;
    }
    cout<<mx<<endl;
}
*/
