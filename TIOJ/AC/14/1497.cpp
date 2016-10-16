#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

string s;
struct aa{int x,y,n,rank;};
aa _[100005];
int n;
bool C1(const aa &lh,const aa &rh){
    if(lh.x!=rh.x)return lh.x<rh.x;
    else return lh.y<rh.y;
}
bool C2(const aa &lh,const aa &rh){
    return lh.n<rh.n;
}
void ranking(){
    // cout<<"   ";for(int i=0;i<n;++i)cout<<"("<<_[i].x<<" "<<_[i].y<<") ";cout<<endl;
    sort(_,_+n,C1);
    // cout<<"-> ";for(int i=0;i<n;++i)cout<<"("<<_[i].x<<" "<<_[i].y<<") ";cout<<endl;
    _[0].rank=1;
    for(int i=1;i<n;++i){
        if(_[i].x!=_[i-1].x || (_[i].x==_[i-1].x&&_[i].y!=_[i-1].y))_[i].rank=_[i-1].rank+1;
        else _[i].rank=_[i-1].rank;
    }
    for(int i=0;i<n;++i){
        _[i].x=_[i].rank;
    }
    sort(_,_+n,C2);
}

void prefixDoubling(){
    for(int i=0;i<n;++i){
        _[i].x=(int)s[i];
        _[i].n=i;
    }
    // for(int i=0;i<n;++i)cout<<_[i].x<<'\n';
    ranking();
    for(int i=1;i<=n;i<<=1){
        for(int j=0;j<n;++j){
            _[j].y=(j+i<n?_[j+i].x:0);
        }
        // for(int i=0;i<n;++i)cout<<_[i].x<<' ';cout<<endl;
        ranking();
    }
    sort(_,_+n,C1);
}

int main(){
    ios_base::sync_with_stdio(0);
    getline(cin,s);
    n=(int)s.length();
    prefixDoubling();
    for(int i=0;i<n;++i)cout<<_[i].n<<'\n';
}
