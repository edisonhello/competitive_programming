#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) reserve(x)
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define F_1 cin.tie(0)
#define F_2 ios_base::sync_with_stdio(0)
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
}

int n;
int cnt;

void o(int a,int b){
    printf("#%d : move the dish from #%d to #%d\n",cnt++,a,b);
}

void Hn(int from,int dist,int step,int tmp){
    if(step==1){
        o(from,dist);
        return;
    }
    Hn(from,tmp,step-1,dist);
    o(from,dist);
    Hn(tmp,dist,step-1,from);
    return;
}

int main(){
    // F_1;F_2;
    cin>>n;
    cnt=1;
    Hn(1,3,n,2);
}
