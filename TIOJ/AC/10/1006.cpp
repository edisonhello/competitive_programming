#include<iostream>
using namespace std;
#include<vector>
#define vint vector<int>
#define pb(x) push_back(x)
#define sz size()
#define bg begin()

vint a,b;

bool small(vint a,vint b){
    while(a.sz && a[0]==0)a.erase(a.bg);
    while(b.sz && b[0]==0)b.erase(b.bg);
    if(a.sz!=b.sz)return a.sz<b.sz;
    for(auto i=0u;i<a.sz;++i){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    return 0;
}

vint times(vint a,int t){
    for(auto &c:a)c*=t;
    for(auto i=a.sz-1;i>0;--i){
        if(a[i]>9){
            a[i-1]+=a[i]/10;
            a[i]%=10;
        }
    }
    while(a[0]>9){
        int of=a[0]/10;
        a[0]%=10;
        a.insert(a.bg,of);
    }
    return a;
}
void mns(vint &a,vint b){
    for(auto i=0u;i<b.sz;++i){
        a[i]-=b[i];
    }
    for(auto i=b.sz-1;i>0;--i){
        while(a[i]<0){
            a[i]+=10;
            --a[i-1];
        }
    }
}

vint div(vint a,vint b){
    vint ans;
    if(small(a,b)){
        ans.pb(0);
        return ans;
    }
    for(auto i=0u;i<=b.sz;++i)a.insert(a.bg,0);
    auto tk=b.sz+1;
    while(a.sz>b.sz){
        vint t,tt;
        t.assign(a.bg,a.bg+tk);
        int tm=0;
        while(1){
            tt=times(b,tm);
            if(small(t,tt)){
                --tm;tt=times(b,tm);
                break;
            }
            ++tm;
        }
        while(tt.sz<tk)tt.insert(tt.bg,0);
        mns(a,tt);
        ans.pb(tm);
        a.erase(a.bg);
    }
    while(ans[0]==0)ans.erase(ans.bg);
    return ans;
}

int main(){
    string sa,sb;
    cin>>sa>>sb;
    // if(sb=="1"){cou}
    for(auto &c:sa)a.pb(c-'0');
    for(auto &c:sb)b.pb(c-'0');
    vint ans=div(a,b);
    for(auto &c:ans)cout<<c;cout<<endl;
}
