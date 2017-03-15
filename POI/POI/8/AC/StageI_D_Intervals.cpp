#include<bits/stdc++.h>
using namespace std;

struct act{int p,t;} a[100009];
bool cmpp(const act &a,const act &b){return a.p==b.p?a.t>b.t:a.p<b.p;}
struct seg{int l,r;};
vector<seg> v;
vector<int> self;

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int l,r;cin>>l>>r;
        act tmp;tmp.p=l,tmp.t=1;a[2*i]=tmp;
        tmp.p=r;tmp.t=-1;a[2*i+1]=tmp;
        if(l==r)self.push_back(l);
    }
    sort(a,a+2*n,cmpp); int lim=a[2*n-1].p;
    int l=0,cnt=0;
    for(int i=1,ptr=0;i<=lim;++i){
        while(ptr<2*n && a[ptr].p<=i && a[ptr].t==1){
            // cout<<ptr<<" "<<i<<endl;
            cnt+=a[ptr].t;
            ++ptr;
        }
        if(cnt>0 && l==0){
            l=i;
        }
        while(ptr<2*n && a[ptr].p<=i && a[ptr].t==-1){
            // cout<<ptr<<" "<<i<<endl;
            cnt+=a[ptr].t;
            ++ptr;
        }
        if(cnt==0 && l){
            seg tmp;tmp.l=l,tmp.r=i;
            v.push_back(tmp);
            l=0;
        }
    }
    if(v.size()==0)cout<<1<<" "<<1<<endl;
    for(int i=0;i<v.size();++i){
        cout<<v[i].l<<" "<<v[i].r<<endl;
    }
}
// AC
