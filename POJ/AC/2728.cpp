#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;

int n;
double x[1111],y[1111],z[1111];
double xy[1111][1111];

#define sq(x) ((x)*(x))

inline double gd(int i,int j,double mid){
    return abs(z[i]-z[j])*mid-xy[i][j];
}

double d[1111];
bitset<1111> v;
double test(double mid){
    v.reset(); v[0]=1;
    for(int i=1;i<n;++i)d[i]=gd(0,i,mid);
    double tot=0;
    while("meow"){
        double mnd=1e15; int idx=-1;
        for(int i=1;i<n;++i){
            if(v[i])continue;
            if(d[i]<mnd){
                mnd=d[i];
                idx=i;
            }
        }
        if(idx==-1)break;
        v[idx]=1;
        tot+=d[idx];
        for(int i=1;i<n;++i){
            if(v[i])continue;
            d[i]=min(d[i],gd(idx,i,mid));
        }
    }
    return tot;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>n,n){
        for(int i=0;i<n;++i)cin>>x[i]>>y[i]>>z[i];
        double mx=0;
        for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)xy[i][j]=xy[j][i]=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])),mx=max(mx,xy[i][j]/abs(z[i]-z[j]));
        double L=0,R=mx;
        while(R-L>1e-12){
            double mid=(L+R)/2;
            if(test(mid)>=0)R=mid;
            else L=mid;
        }
        cout<<fixed<<setprecision(3)<<1./L<<'\n';
    }
}

