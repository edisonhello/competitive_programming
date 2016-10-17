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

int F[10005];

int KMP(string &s,string &t){
    if(t.length()>s.length())return 0;
    MS0(F);
    int cnt=0;
    F[0]=-1;F[1]=0;
    for(int i=1,j=1;i<(int)t.length();++i,j=i){
        while(t[i]!=t[F[j]] && j)j=F[j];
        F[i+1]=F[j]+1;
    }
    for(int i=0,j=0;i+j<(int)s.length();j++){
        if(s[i+j]==t[j]){
            if(j==(int)t.length()-1){
                cnt++;
                i+=t.length()-F[j+1];
                j-=t.length()-F[j+1];
            }
        }
        else{
            i+=j-F[j];
            j-=j-F[j]+1;
            if(j<-1)j=-1;
        }
    }
    return cnt;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        string a;cin>>a;
        int n;cin>>n;for(int i=0;i<n;++i){
            string c;cin>>c;
            cout<<KMP(a,c)<<'\n';
        }
    }
}
