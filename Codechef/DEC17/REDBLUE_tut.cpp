#include<bits/stdc++.h>
using namespace std;
#define ld long double 
 
const ld eps=1e-5;
 
struct point{
    ld x,y;
    int type,i;
} pt[2004];
 
vector<pair<ld,point>> p;
 
ld angle(int ref,int inp){
    ld dx=pt[inp].x-pt[ref].x,dy=pt[inp].y-pt[ref].y;
    if(abs(dy)<1e-5)dy=-dy,dx=-dx;
    if(abs(dx)<eps)return 3.1415926535/2;
    ld ang=atan(dy/dx);
    return ang<0?3.14159265358979+ang:ang;
}
 
void solll(int n,int m){
    for(int i=0;i<n;++i){
        ld x,y; cin>>x>>y;
        pt[i]={x,y,1,i};
    }
    for(int i=0;i<m;++i){
        ld x,y; cin>>x>>y;
        pt[n+i]={x,y,2,n+i};
    }
    int mn=999888777;
    for(int i=0,ref=0;i<n+m;++i,++ref){
        p.clear();
        for(int j=0;j<n+m;++j){
            if(i==j)continue;
            p.emplace_back(angle(i,j),pt[j]);
        }
        sort(p.begin(),p.end(),[](const pair<ld,point> &a,const pair<ld,point> &b){return a.first<b.first;});
        // cout<<"base is :"<<pt[i].x<<" "<<pt[i].y<<", "<<endl;
        // cout<<"p: "; for(auto i:p)cout<<"["<<i.first<<", ("<<i.second.x<<" "<<i.second.y<<")] "; cout<<endl;
        // ld A=(p[0].second.y-pt[i].y)/(p[0].second.x-pt[i].x),B=-1,C=pt[i].y-(p[0].second.y-pt[i].y)/(p[0].second.x-pt[i].x)*pt[i].x;
        ld A=(p[0].second.y-pt[i].y),B=-1*(p[0].second.x-pt[i].x),C=pt[i].y*(p[0].second.x-pt[i].x)-(p[0].second.y-pt[i].y)*pt[i].x;
        if(B>0)A=-A,B=-B,C=-C;
        // cout<<"line function: A:"<<A<<" B:"<<B<<" C:"<<C<<endl;
        int pos[2]={0},neg[2]={0};
        for(auto &i:p){
            if(i.second.i==p[0].second.i)continue;
            // cout<<"for point ("<<i.second.x<<","<<i.second.y<<") is ";
            if(A*i.second.x+B*i.second.y+C>0)++pos[i.second.type-1];// ,cout<<"pos"<<endl;
            else ++neg[i.second.type-1];// ,cout<<"neg"<<endl;
        }
        // cout<<"init pos: "<<pos[0]<<" "<<pos[1]<<" , neg: "<<neg[0]<<" "<<neg[1]<<endl;
        mn=min(mn,min(pos[0]+neg[1],pos[1]+neg[0]));
        for(int i=1;i<p.size();++i){
            if(p[i-1].second.y>=pt[ref].y)++pos[p[i-1].second.type-1];
            else ++neg[p[i-1].second.type-1];
            if(p[i].second.y>=pt[ref].y)--neg[p[i].second.type-1];
            else --pos[p[i].second.type-1];
            // cout<<"     pos: "<<pos[0]<<" "<<pos[1]<<" , neg: "<<neg[0]<<" "<<neg[1]<<endl;
            mn=min(mn,min(pos[0]+neg[1],pos[1]+neg[0]));
        }
        // cout<<"now mn: "<<mn<<endl;
        // cout<<endl;
    }
    cout<<mn<<endl;
}
 
int main(){
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        solll(n,m);
    }
}
 
// tutorial WA 1-8 2-1 2-2
