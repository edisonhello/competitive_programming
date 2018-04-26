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
point operator-(point a,point b){
    point p; p.x=a.x-b.x; p.y=a.y-b.y; return p;
}
long long operator^(point a,point b){
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}

vector<int> idxs;
char pt1,pt2,pt3,pt4;

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
        else if(p[i].ch==pt3)p[i].c=4;
        else if(p[i].ch==pt4)p[i].c=8;
        // else idxs.push_back(i);
        if(p[i].c)idxs.push_back(i);
    }

    int a1=0,a2=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)continue;
            if((p[i].c==1 || p[i].c==2))continue;
            if((p[j].c==4 || p[j].c==8))continue;
            int pos=0,neg=0,ok=1;
            for(int k:idxs){
                if(k==i || k==j || p[k].c==0)continue;
                long long va=(p[j]-p[i])^(p[k]-p[i]);
                if(va>0)pos|=p[k].c;
                else neg|=p[k].c;
                if((pos&12) && (neg&12))ok=0;
                if((pos&3) && (neg&3))ok=0;
                if((pos&12) && (pos&3))ok=0;
                if((neg&3) && (neg&12))ok=0;
                if(!ok)break;
            }
            if(ok)++a1;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)continue;
            if((p[i].c==1 || p[i].c==4))continue;
            if((p[j].c==2 || p[j].c==8))continue;
            int pos=0,neg=0,ok=1;
            for(int k:idxs){
                if(k==i || k==j || p[k].c==0)continue;
                long long va=(p[j]-p[i])^(p[k]-p[i]);
                if(va>0)pos|=p[k].c;
                else neg|=p[k].c;
                if((pos&10) && (neg&10))ok=0;
                if((pos&5) && (neg&5))ok=0;
                if((pos&10) && (pos&5))ok=0;
                if((neg&5) && (neg&10))ok=0;
                if(!ok)break;
            }
            if(ok)++a2;
        }
    }

    cout<<1ll*a1*a2/4<<endl;
}
