#include<bitset>
#include<iostream>
#include<utility>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y));
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
struct li{
    int arr[505];
    bitset<505> used;
    int size_;
    int at(int where){
        for(int i=0,u=0;i<505;++i){
            if(!this->used[i]){ ++u;
                if(u>where)return this->arr[i];
            }
        }
        return -7122;
    }
    int set(int where,int val){
        for(int i=0,u=0;i<505;++i){
            if(!this->used[i]){ ++u;
                if(u>where){size_=max(size_,u);return this->arr[i]=val;}
            }
        }
        return -7122;
    }
    int size(){
        return this->size_;
    }
    void erase(int where){
        for(int i=0,u=0;i<505;++i){
            if(!this->used[i]){ ++u;
                if(u>where){
                    this->used[i]=1;
                    --this->size_;
                    return;
                }
            }
        }
    }
} a,b;
int n,k;
vector<pair<int,char>> ans;
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0,t;i<n;++i){
        cin>>t;
        a.set(i,t);
    }
    cin>>k;
    for(int i=0,t;i<k;++i){
        cin>>t;
        b.set(i,t);
    }
    int i=0,j=0,cnt=1;
    while(a.size()>k){
        // cout<<"size: "<<a.size()<<endl;
        // for(int l=0;l<a.size();++l){
        //     cout<<a.at(l)<<" ";
        // }
        // cout<<endl;
        int aat0=a.at(0),bat0=b.at(0);
        if(aat0>bat0){
            cout<<"NO\n";
            return 0;
        }
        else if(aat0==bat0){
            // cout<<"erase.\n";
            a.erase(0);
            b.erase(0);
            ++cnt;
            --k;
        }
        else{
            int prv=aat0,nw,l=1;
            for(;l<n;++l){
                nw=a.at(l);
                if(nw==prv)prv=nw;
                else break;
            }
            if(nw>prv){
                // cout<<"eat. "<<cnt+l<<" "<<'L'<<endl;
                ans.push_back({cnt+l,'L'});
                a.set(l-1,prv+nw);
                a.erase(l);
            }
            else if(nw<prv){
                // cout<<"eat. "<<cnt+l-1<<"(l-1="<<l-1<<") "<<'R'<<endl;
                ans.push_back({cnt+l-1,'R'});
                a.set(l-1,prv+nw);
                a.erase(l);
            }
        }
    }
    for(int i=0;i<k;++i){
        if(a.at(i)!=b.at(i)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for(auto i:ans){
        cout<<i.X<<" "<<i.Y<<endl;
    }
}
