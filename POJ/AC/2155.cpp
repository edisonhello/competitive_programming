#include<iostream>
#include<cstring>
using namespace std;
#define int long long

int lowbit(int x){return x&-x;}
int BIT[1234][1234],n;
void modify(int x,int y,int v){
    for(int i=x;i<=n+5;i+=lowbit(i)){
        for(int j=y;j<=n+5;j+=lowbit(j)){
            BIT[i][j]+=v;
        }
    }
}
int query(int x,int y,int rt=0){
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            rt+=BIT[i][j];
        }
    } return rt;
}
signed main(){
    int ts;cin>>ts;while(ts--){
        memset(BIT,0,sizeof(BIT));
        int t;cin>>n>>t;
        while(t--){
            char c;cin>>c;
            if(c=='C'){
                int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
                modify(x1,y1,1), modify(x2+1,y1,1);
                modify(x1,y2+1,1), modify(x2+1,y2+1,1);
            }
            else{
                int x1,y1;cin>>x1>>y1;
                int rs=query(x1,y1)&1;
                cout<<rs<<endl;
            }
        }
        cout<<endl;
    }
}
