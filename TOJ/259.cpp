#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

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

int n;
int a[10005],l[10005],r[10005];
int pos[10005],len;
int mx;

int main(){
    // cout<<"af"<<endl;
    while(cin>>n){
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(pos,-1,sizeof(pos));
        len=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>pos[len-1]){
                pos[len++]=a[i];
            }
            else{
                *lower_bound(pos,pos+len,a[i])=a[i];
            }
            l[i]=len;
        }
        len=0;
        memset(pos,-1,sizeof(pos));
        for(int i=n-1;i>=0;i--){
            if(a[i]>pos[len-1]){
                pos[len++]=a[i];
            }
            else{
                *lower_bound(pos,pos+len,a[i])=a[i];
            }
            r[i]=len;
        }
        mx=0;
        for(int i=0;i<n;i++){
            mx=max(min(l[i],r[i])*2-1,mx);
        }
        // cout<<"l:";for(int i=0;i<n;i++)cout<<l[i]<<" ";cout<<endl;
        // cout<<"r:";for(int i=0;i<n;i++)cout<<r[i]<<" ";cout<<endl;
        cout<<mx<<endl;
    }
}
