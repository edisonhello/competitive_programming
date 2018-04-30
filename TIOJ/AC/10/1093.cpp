#include<bits/stdc++.h>
using namespace std;

const double eps=1e-7;

double r;
pair<double,double> pos[1000004],c;

pair<double,double> operator+(const pair<double,double> &a,const pair<double,double> &b){ return make_pair(b.first+a.first,b.second+a.second); }
pair<double,double> operator-(const pair<double,double> &a,const pair<double,double> &b){ return make_pair(b.first-a.first,b.second-a.second); }
pair<double,double> operator*(const pair<double,double> &a,const double &x){ return make_pair(a.first*x,a.second*x); }
pair<double,double> operator/(const pair<double,double> &a,const double &x){ return make_pair(a.first/x,a.second/x); }


double dis(const pair<double,double> &a){ return sqrt(pow(a.first,2)+pow(a.second,2)); }
double dis(const pair<double,double> &a,const pair<double,double> &b){ return dis(b-a); }

int main(){
    srand(clock());
    int n,m; while(cin>>n>>m,n){
        for(int i=0;i<m;++i)cin>>pos[i].first>>pos[i].second;
        random_shuffle(pos,pos+m);
        c=pos[0]; r=0;
        for(int i=1;i<m;++i){
            if(dis(c,pos[i])<r+eps)continue;
            c=pos[i]; r=0;
            for(int j=0;j<i;++j){
                if(dis(c,pos[j])<r+eps)continue;
                c=(pos[i]+pos[j])/2; r=dis(c,pos[j]);
                for(int k=0;k<j;++k){
                    if(dis(c,pos[k])<r+eps)continue;
                    auto ijm=(pos[i]+pos[j])/2;
                    auto jkm=(pos[j]+pos[k])/2;
                    auto ijg=(pos[j]-pos[i]);
                    auto jkg=(pos[k]-pos[j]);
                    swap(ijg.first,ijg.second); ijg.second*=-1;
                    swap(jkg.first,jkg.second); jkg.second*=-1;
                    #ifdef FORMULA
                    ijm.first+ijg.first*x=jkm.first+jkg.first*y
                    ijg.first*x-jkg.first*y=jkm.first-ijm.first;
                    ( first -> second )
                    #endif
                    double d=ijg.first*(-jkg.second)-ijg.second*(-jkg.first);
                    double dx=(jkm.first-ijm.first)*(-jkg.second)-(jkm.second-ijm.second)*(-jkg.first);
                    // double dy=ijg.first*(-(jkm.second-ijm.second))-ijg.second*(-(jkm.first-ijm.first));
                    c=ijm+ijg*(dx/d);
                    r=dis(c,pos[k]);
                }
            }
        }
        cout<<fixed<<setprecision(3)<<r<<endl;
    }
}
