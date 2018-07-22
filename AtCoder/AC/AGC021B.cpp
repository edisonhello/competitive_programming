#include<bits/stdc++.h>
using namespace std;

pair<double,double> p[104];
int cnt[104];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i].first>>p[i].second;
        // p[i].first=rand()%1000000;
        // p[i].second=rand()%1000000;
    }

    int point_at_round=8000000;
    double PI=acos(-1);
    double all_deg=2*PI;
    double delta=all_deg/point_at_round;

    for(int i=0;i<point_at_round;++i){
        double x=cos(delta*i)*1e11,y=sin(delta*i)*1e11;
        double md=1e25; int mdi=-1;
        for(int i=1;i<=n;++i){
#define sq(x) ((x)*(x))
            double nd=sq(p[i].first-x)+sq(p[i].second-y);
            if(nd<md){
                md=nd;
                mdi=i;
            }
        }
        ++cnt[mdi];
    }

    for(int i=1;i<=n;++i)cout<<fixed<<setprecision(9)<<(double)cnt[i]/point_at_round<<'\n';
}

