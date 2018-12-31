#include<bits/stdc++.h>
using namespace std;
#define point pair<double,double>
#define x first
#define y second

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#else
#define PDE(...) ;
#endif

const double pi=acos(-1);

point operator+(const point a,const point b){ return point(a.x+b.x,a.y+b.y); }
point operator-(const point a,const point b){ return point(a.x-b.x,a.y-b.y); }
point operator*(const point a,const double b){ return point(a.x*b,a.y*b); }
double operator*(const point a,const point b){ return a.x*b.x+a.y*b.y; }
point operator/(const point a,const double b){ return point(a.x/b,a.y/b); }

double abs(const point x){ return hypot(x.x,x.y); }

point norm(const point x){
    double z=abs(x);
    return x/z;
}

point turn(point x,double theta){
    return point(x.x*cos(theta)-x.y*sin(theta),x.x*sin(theta)+x.y*cos(theta));
}

const double R = 100;

point pos[10];
vector<pair<point,int>> points;
vector<pair<int,double>> G[533];
double d[777][777];

int main(){
    int n; point p; cin>>n>>p.x>>p.y;
    for(int i=0;i<n;++i)cin>>pos[i].x>>pos[i].y;
    points.emplace_back(point(0,0),-1);
    points.emplace_back(p,-2);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            point vec=pos[j]-pos[i];
            vec=norm(point(vec.y,-vec.x))*R;
            points.emplace_back(pos[i]+vec,i);
            points.emplace_back(pos[i]-vec,i);
            points.emplace_back(pos[j]+vec,j);
            points.emplace_back(pos[j]-vec,j);
        }
        double theta=asin(R/abs(pos[i]));
        double dis=sqrt(abs(pos[i])*abs(pos[i])-R*R);
        PDE(theta,dis);
        point vec=pos[i];
        point vec1=norm(turn(vec,theta))*dis,vec2=norm(turn(vec,-theta))*dis;
        points.emplace_back(vec1,i);
        points.emplace_back(vec2,i);
        PDE(i,vec1,vec2);
        theta=asin(R/abs(pos[i]-p));
        dis=sqrt(abs(pos[i]-p)*abs(pos[i]-p)-R*R);
        vec=pos[i]-p;
        vec1=norm(turn(vec,theta))*dis,vec2=norm(turn(vec,-theta))*dis;
        points.emplace_back(p+vec1,i);
        points.emplace_back(p+vec2,i);
    }
    int m=int(points.size());
    PDE(points);
    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            if(points[i].second == points[j].second){
                vector<pair<double,double>> cant;
                int ci=points[i].second;
                for(int cj=0;cj<n;++cj)if(ci!=cj){
                    if(abs(pos[ci]-pos[cj]) >= 2*R)continue;
                    point vec=pos[cj]-pos[ci];
                    double theta=acos((abs(vec/2))/R);
                    double angle=atan2(vec.y,vec.x);
                    double L=angle-theta,R=angle+theta;
                    if(L<0)L+=2*pi; if(R>=2*pi)R-=2*pi;
                    cant.emplace_back(L,R);
                }
                point vec1=points[i].first-pos[ci],vec2=points[j].first-pos[ci];
                double ang1=atan2(vec1.y,vec1.x),ang2=atan2(vec2.y,vec2.x);
                auto inseg=[&](double x,double L,double R)->bool{
                    if(R<L)R+=2*pi;
                    if(L<=x && x<=R)return 1;
                    L-=2*pi; R-=2*pi;
                    if(L<=x && x<=R)return 1;
                    L-=-4*pi; R-=-4*pi;
                    if(L<=x && x<=R)return 1;
                    return 0;
                };
                auto nosect=[&](double ang1,double ang2)->bool{
                    for(auto &p:cant){
                        if(inseg(ang1,p.first,p.second))return 0;
                        if(inseg(ang2,p.first,p.second))return 0;
                        if(inseg(p.first,ang1,ang2))return 0;
                        if(inseg(p.second,ang1,ang2))return 0;
                    }
                    return 1;
                };
                if(nosect(ang1,ang2)){
                    double ang=ang2-ang1;
                    if(ang<0)ang+=2*pi;
                    G[i].emplace_back(j,R*ang);
                    G[j].emplace_back(i,R*ang);
                }
                if(nosect(ang2,ang1)){
                    double ang=ang1-ang2;
                    if(ang<0)ang+=2*pi;
                    G[i].emplace_back(j,R*ang);
                    G[j].emplace_back(i,R*ang);
                }
            }
            else{
                double dx=points[j].first.x-points[i].first.x,dy=points[j].first.y-points[i].first.y;
                double c=-(points[i].first.x*dy-points[i].first.y*dx);
                double a=dy,b=-dx;
                bool cut=0;
                if(i==0 && j==30)PDE(a,b,c);
                for(int z=0;z<n;++z){
                    auto inmid=[&](const int z)->bool{
                        point vec=points[j].first-points[i].first;
                        point vec1=pos[z]-points[i].first;
                        if(vec*vec1<0)return 0;
                        vec=points[i].first-points[j].first;
                        vec1=pos[z]-points[j].first;
                        if(vec*vec1<0)return 0;
                        return 1;
                    };
                    if(inmid(z)){
                        if(abs(a*pos[z].x+b*pos[z].y+c)/hypot(a,b)<R-1e-8)cut=1;
                    }
                    else{
                        if(min(abs(pos[z]-points[i].first),abs(pos[z]-points[j].first))<R-1e-8)cut=1;
                    }
                    if(i==0 && j==30)PDE(i,j,z,cut,abs(a*pos[z].x+b*pos[z].y+c)/hypot(a,b));
                    /* if(abs(a*pos[z].x+b*pos[z].y+c)/hypot(a,b)<R-1e-8)cut=1;
                    if(i==0 && j==30)PDE(i,j,z,cut,abs(a*pos[z].x+b*pos[z].y+c)/hypot(a,b)); */
                }
                if(cut)continue;
                G[i].emplace_back(j,hypot(dx,dy));
                G[j].emplace_back(i,hypot(dx,dy));
            }
        }
    }    
    for(int i=0;i<m;++i)for(int j=0;j<m;++j)d[i][j]=1e9,d[i][i]=0;
    for(int i=0;i<m;++i){
        for(auto &p:G[i]){
            d[i][p.first]=min(d[i][p.first],p.second);
            // PDE(i,p);
        }
    }
    for(int k=0;k<m;++k)for(int i=0;i<m;++i)for(int j=0;j<m;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cout<<d[0][1]<<endl;
    PDE(d[0][30]);

}

// 0 = dy*x - dx*y + b
