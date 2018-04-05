#include<bits/stdc++.h>
using namespace std;

vector<int> luc;

int init(int dg){
    for(int i=0;i<(1<<dg);++i){
        int add=0,base=1;
        for(int j=0;j<dg;++j){
            add+=base*((i&(1<<j))?7:4);
            base*=10;
        }
        luc.push_back(add);
    }
}
void init(){
    luc.push_back(-7122);
    for(int i=1;i<=9;++i)init(i);
    luc.push_back(1000007122);
    // for(int i:luc)cout<<i<<" "; cout<<endl;
    // cout<<"luc size: "<<luc.size()<<endl;
}

int main(){
    init();
    int pl,pr,vl,vr,k; cin>>pl>>pr>>vl>>vr>>k;
    int lptr=1,rptr=k;
    long double ans=0;
    while(rptr<luc.size()-1){
        int pll=max(luc[lptr-1]+1,pl);
        int prr=min(luc[lptr],pr);
        int vll=max(luc[rptr],vl);
        int vrr=min(luc[rptr+1]-1,vr);
        if(pll<=prr && vll<=vrr){
            ans+=((long double)(prr-pll+1)/(pr-pl+1))*((long double)(vrr-vll+1)/(vr-vl+1));
        }
        ++lptr, ++rptr;
    }
    swap(pl,vl); swap(pr,vr);
    lptr=1,rptr=k;
    while(rptr<luc.size()-1){
        int pll=max(luc[lptr-1]+1,pl);
        int prr=min(luc[lptr],pr);
        int vll=max(luc[rptr],vl);
        int vrr=min(luc[rptr+1]-1,vr);
        if(pll<=prr && vll<=vrr){
            ans+=((long double)(prr-pll+1)/(pr-pl+1))*((long double)(vrr-vll+1)/(vr-vl+1));
        }
        ++lptr, ++rptr;
    }
    // if(vl==pl && pl==vr &&  vr==pr)ans/=2;
    if(k==1)for(int i=1;i<luc.size()-1;++i){
        if(pl<=luc[i] && luc[i]<=pr && vl<=luc[i] && luc[i]<=vr){
            ans-=((long double)1/(pr-pl+1))*((long double)1/(vr-vl+1));
        }
    }
    cout<<fixed<<setprecision(20)<<ans<<endl;
}
