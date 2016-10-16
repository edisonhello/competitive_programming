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

int n;
map<string,pair<int,PQ<int,vector<int>,greater<int>>>> m;

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        m.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            string s;int c;cin>>s>>c;
            m[s].X+=c;
            m[s].Y.push(c);
        }
        int moves=0;
        for(auto ty:m){
            if(ty.X[ty.X.length()-1]=='r'){
                while(S(ty.Y.Y)>1){
                    int t1=ty.Y.Y.top();ty.Y.Y.pop();
                    int t2=ty.Y.Y.top();ty.Y.Y.pop();
                    if(t2==100){
                        break;
                    }
                    if((t1+t2)>100){
                        ty.Y.Y.push(100);
                        ty.Y.Y.push((t1+t2)%100);
                    }
                    else{
                        ty.Y.Y.push(t1+t2);
                    }
                    ++moves;
                }
            }
            else{
                while(S(ty.Y.Y)>1){
                    int t1=ty.Y.Y.top();ty.Y.Y.pop();
                    int t2=ty.Y.Y.top();ty.Y.Y.pop();
                    if(t2==1000){
                        break;
                    }
                    if((t1+t2)>1000){
                        ty.Y.Y.push(1000);
                        ty.Y.Y.push((t1+t2)%1000);
                    }
                    else{
                        ty.Y.Y.push(t1+t2);
                    }
                    ++moves;
                }
            }
        }
        cout<<moves<<'\n';
    }
}
