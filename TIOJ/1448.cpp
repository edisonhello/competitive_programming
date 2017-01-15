#include<iostream>
using namespace std;
#include<set>

int djs[1500015];

int F(int x){if(djs[x]==x)return x;return djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);if(x==y)return;djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=3*n;++i)djs[i]=i;
    int fake=0;
    while(k--){
        int d,x,y;cin>>d>>x>>y;
        if(x>n || y>n){++fake;continue;}
        if(d==2&&x==y){++fake;continue;}
        if(x==y)continue;
        if(d==1){
            if(!C(x,y+n) && !C(x+n,y) && !C(x+n,y+2*n) && !C(x+2*n,y+n) && !C(x,y+2*n) && !C(x+2*n,y)){
                U(x,y);
                U(x+n,y+n);
                U(x+2*n,y+2*n);
            }
            else ++fake;
        }
        if(d==2){
            if(C(x,y) || C(x+n,y+n) || C(x+2*n,y+2*n))++fake;
            else{
                if(!C(x,y+n)){
                    U(x,y+n);
                    U(x+n,y);
                }
                else if(!C(x+n,y+2*n)){
                    U(x+n,y+2*n);
                    U(x+2*n,y+n);
                }
                else if(!C(x+2*n,y)){
                    U(x+2*n,y);
                    U(x,y+2*n);
                }
            }
        }
    }
    cout<<fake<<endl;;
}
