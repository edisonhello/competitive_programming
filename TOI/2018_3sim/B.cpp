#include<bits/stdc++.h>
using namespace std;

//#define PDE(...) ;
//#define DEBUG 0

#define DEBUG 1
#define PDE(x) cout<<#x<<" : "<<x<<endl
#define PDE2(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl

int n,ans;

struct point{
    int x,y,c;
    char ch;
} p[1111],tmp[1111];

struct line{
    double a,b,c; // ax+by=c
    line(const point &p1,const point &p2){
        if(p1.x==p2.x){a=1; b=0; c=p1.x; return;}
        double ta=(p2.y-p1.y)/(p2.x-p1.x);
        double tb=p1.y-a*p1.x;
        a=-ta; b=1; c=tb;
    }
    double get(const point &p){
        return p.x*a+p.y*b-c;
    }
    bool slope_hor(){
        if(b==0)return 0;
        if(abs(a)>=sqrt(2)-1e-8)return 0;
        return 1;
    }
};

void check(){
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            PDE2(i,j);
            line L(p[i],p[j]);
            if(!L.slope_hor())continue;
            int pos34=0,pos12=0,neg34=0,neg12=0;
            for(int k=0;k<n;++k){
                if(k==i || k==j)continue;
                if(L.get(p[k])>0){
                    if(p[k].c>2)++pos34;
                    else if(p[k].c)++pos12;
                }
                else{
                    if(p[k].c>2)++neg34;
                    else if(p[k].c)++neg12;
                }
            }
            if(p[i].c==3 || p[i].c==4)++neg34;
            else if(p[i].c==1 || p[i].c==2)++neg12;
            if(p[j].c==3 || p[j].c==4)++neg34;
            else if(p[j].c==1 || p[j].c==2)++neg12;

            PDE2(pos34,pos12);
            PDE2(neg34,neg12);
            if(pos34 && pos12)continue;
            if(pos34 && neg34)continue;
            if(neg34 && neg12)continue;
            if(pos12 && neg12)continue;
            PDE("roll");
            for(int i=0;i<n;++i){
                for(int j=0,jj=0;j<n;++j,++jj){
                    if(jj==i){--j; continue;}
                    tmp[j]=p[jj];
                    tmp[j].x-=p[i].x;
                    tmp[j].y-=p[i].y;
                }
                auto cmp=[&](point p1,point p2)->bool{
                    if(p1.y==0)return 1;
                    if(p2.y==0)return 0;
                    if(p1.y<0)p1.y=-p1.y,p1.x=-p1.x;
                    if(p2.y<0)p2.y=-p2.y,p2.x=-p2.x;
                    return p1.x*p2.y-p1.y*p2.x>0;
                };
                sort(tmp,tmp+n-1,cmp);
                if(DEBUG){
                    cout<<"now points are: ";
                    for(int i=0;i<n-1;++i)cout<<"("<<tmp[i].x<<" , "<<tmp[i].y<<") ";
                    cout<<endl;
                }
                line L2(p[i],tmp[0]);
                int pos13=0,neg13=0,pos24=0,neg24=0;
                for(int j=1;j<n-1;++j){
                    if(L2.get(tmp[j])>0){
                        if(tmp[j].c&1)++pos13;
                        else if(tmp[j].c&6)++pos24;
                    }
                    else{
                        if(tmp[j].c&1)++neg13;
                        else if(tmp[j].c&6)++neg24;
                    }
                }
                if(p[i].c&1)++pos13;
                else if(p[i].c&6)++pos24;
                PDE(i);
                PDE2(pos13,pos24);
                PDE2(neg13,neg24);
                for(int j=0;j<n-1;++j){
                    if(tmp[j].y>=0){
                        if(tmp[j].c&1)++neg13;
                        else if(tmp[j].c&6)++neg24;
                    }
                    else{
                        if(tmp[j].c&1)++pos13;
                        else if(tmp[j].c&6)++pos24;
                    }
                    bool ok=1;
                    if(pos13 && neg13)ok=0;
                    if(pos24 && neg24)ok=0;
                    if(pos13 && pos24)ok=0;
                    if(neg13 && neg24)ok=0;
                    PDE2(j,ok);
                    PDE2(pos13,pos24);
                    PDE2(neg13,neg24);
                    if(ok){
                        int mul=1;
                        /* if(p[i].c==0)mul<<=1;
                        if(tmp[j].c==0)mul<<=1; */
                        ans+=mul;
                        PDE(mul);
                    }
                    if(tmp[j+1].y>=0){
                        if(tmp[j+1].c&1)--pos13;
                        else if(tmp[j+1].c&6)--pos24;
                    }
                    else{
                        if(tmp[j+1].c&1)--neg13;
                        else if(tmp[j+1].c&6)--neg24;
                    }
                }
            }
        }
    }
}

char pt1,pt2,pt3,pt4;

vector<int> idxs;

void dfs(int now){
    if(now==idxs.size())check();
    else{
        for(int i=1;i<=4;++i){
            p[idxs[now]].c=i;
            dfs(now+1);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>p[i].x>>p[i].y>>p[i].ch;
        if(p[i].x==0 && p[i].y==0)pt1=p[i].ch;
        else if(p[i].x==0 && p[i].y==10000)pt3=p[i].ch;
        else if(p[i].x==10000 && p[i].y==0)pt2=p[i].ch;
        else if(p[i].x==10000 && p[i].y==10000)pt4=p[i].ch;
    }
    for(int i=0;i<n;++i){
        if(p[i].ch==pt1)p[i].c=1;
        else if(p[i].ch==pt2)p[i].c=2;
        else if(p[i].ch==pt3)p[i].c=3;
        else if(p[i].ch==pt4)p[i].c=4;
        else idxs.push_back(i);
    }
    // sort(p,p+n,[](const point &a,const point &b){return a.x<b.x;});
    dfs(0);

    cout<<ans<<endl;
}
