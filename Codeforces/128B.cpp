#include<bits/stdc++.h>
using namespace std;

int x[100005],y[100005],r[100005],sa[100005];

int main(){
    string s; cin>>s;
    // int n=s.size(),k; cin>>k;
    int n=s.size();
    for(int i=0;i<n;++i)x[i]=s[i],sa[i]=i;
    sort(sa,sa+n,[](const int &a,const int &b){return x[a]<x[b];});
    // for(int i=0;i<n;++i)cout<<sa[i]<<" "; cout<<endl;
    for(int D=1;D<n;D<<=1){
        for(int i=0,rk=1;i<n;++i)r[i]=(rk+=(x[sa[i]]!=x[sa[i]-1] || y[sa[i]]!=y[sa[i]-1]));
        for(int i=0;i<n;++i)x[i]=r[i],y[i]=(i+D>=n?0:r[i+D]);
        cout<<"xy: "; for(int i=0;i<n;++i)cout<<"("<<
        sort(sa,sa+n,[](const int &a,const int &b){return x[a]==x[b]?y[a]<y[b]:x[a]<x[b];});
    }
    for(int i=0;i<n;++i)cout<<sa[i]<<endl;
}


/* struct meow{
    int x,y,r,i;
} a[100009];
int pos[100009];

int main(){
    string s; cin>>s;
    // int n=s.size(),k; cin>>k;
    int n=s.size();
    for(int i=0;i<n;++i)a[i].x=s[i],a[i].i=i;
    sort(a,a+n,[](const meow &a,const meow &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    // for(int i=0;i<n;++i)cout<<sa[i]<<" "; cout<<endl;
    for(int D=1;D<n;D<<=1){
        for(int i=0,r=1;i<n;++i)pos[a[i].i]=i,a[i].r=(r+=(a[i].x!=a[i-1].x || a[i].y!=a[i-1].y));
        for(int i=0;i<n;++i)a[i].x=a[i].r,a[i].y=(a[i].i+D>=n?0:a[pos[a[i].i+D]].r);
        sort(a,a+n,[](const meow &a,const meow &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    }
    for(int i=0;i<n;++i)cout<<a[i].i<<endl;
} */
