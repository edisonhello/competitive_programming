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

int n,len,tmp,p,tck;
int a[500005],cur[500005],pos[500005],LIS[500005];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=1;
    len=0;
    while(cin>>tmp/* && tmp!=7122*/){
        a[n]=tmp;
        if(len==0){
            cur[++len]=tmp;
            pos[n]=len;
        }
        else{
            if(tmp>cur[len]){
                cur[++len]=tmp;
                pos[n]=len;
            }
            else{
                p=lower_bound(cur+1,cur+len+1,tmp)-cur;
                cur[p]=tmp;
                pos[n]=p;
            }
        }
        n++;
        // for(int i=1;i<=len;i++)cout<<cur[i]<<" ";
    }
    cout<<len<<"\n-\n";
    tck=len;
    for(int i=n;i;i--){
        if(pos[i]==tck){
            LIS[tck--]=a[i];
        }
    }
    for(int i=1;i<=len;i++)cout<<LIS[i]<<endl;
}
