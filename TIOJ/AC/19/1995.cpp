#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define lb(x) ((x)&-(x))

struct Int{
    unsigned char i[3];
    void input(){scanf("%d",(int*)(i));}
    int getint()const{return (*(int*)(i))&((1<<24)-1);}
    int overget()const{return *(int*)(i);}
    void operator=(const int &a){*(int*)(i)=a|((*(int*)(i))&(-(1<<24)));}
    void overwrite(const int a){*(int*)(i)=a;}
};
bool operator<(const Int &a,const Int &b){return a.getint()<b.getint();}

struct Pair{
    Int a[3];
};

int _buf[55];
Pair p[1000006];
int b[2500006];
//#include<iostream>
void add(int x,int v){
    while(x<2500006){
        b[x]=max(b[x],v);
        x+=lb(x);
    }
}
int query(int x,int v=0){
    while(x>0){
        v=max(v,b[x]);
        x-=lb(x);
    } return v;
}

int main(){
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        p[i].a[0].input();
        p[i].a[1].input();
        p[i].a[2]=i;
    }
    sort(p,p+m,[](const Pair &a,const Pair &b){return a.a[1]<b.a[1];});
    int ptr=0;
    for(int i=0,t;i<m;++i){
        while(ptr<p[i].a[1].getint())++ptr,scanf("%d",&t),add(2500003-ptr,t);
        // (*(Int*)(((unsigned char*)(&p[i].a[1]))-2)).overwrite(query(2500003-p[i].a[0].getint()));
        p[i].a[0].overwrite(query(2500003-p[i].a[0].getint()));
    }
    // for(int i=0;i<m;++i)b[p[i].a[2].getint()]=(*(Int*)(((unsigned char*)(&p[i].a[1]))-2)).overget();
    for(int i=0;i<m;++i)b[p[i].a[2].getint()]=p[i].a[0].overget();
    for(int i=0;i<m;++i)printf("%d\n",b[i]);
}
