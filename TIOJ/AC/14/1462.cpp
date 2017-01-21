#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ld long double

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    ld px,py,eps=1e-6,x,y,vx,vy,nx,ny,dx,dy;
    bool hit;
    while(cin>>n>>t>>px>>py,n){
        hit=0;
        while(n--){
            cin>>x>>y>>vx>>vy;
            dx=x-px,dy=y-py;
            if(fabs(dx)<eps && fabs(dy)<eps){hit=1;continue;}
            nx=x+vx*t,ny=y+vy*t;
            if(fabs(nx-px)<eps && fabs(ny-py)<eps){hit=1;continue;}
            if(fabs(dx)<eps){
                if((ny-py)*(dy)<eps){hit=1;continue;}
            }
            else{
                if(fabs(dy/dx-vy/vx)<eps && (nx-px)*(dx)<eps){hit=1;continue;}
            }
        }
        if(hit)cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
