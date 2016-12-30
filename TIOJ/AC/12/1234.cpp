#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
struct _{int u,d;
_():u(0),d(0){};
_(int a,int b):u(a),d(b){};
bool operator<(const _ &a)const{
    return (ld)this->u/(ld)this->d<(ld)a.u/(ld)a.d;
}};
set<_> s;
int n;

bool mk(_ x){
    if(__gcd(x.u,x.d)!=1)return 1;
    return 0;
}

int main(){
    cin>>n;
    _ t;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            t.u=j;t.d=i;
            s.insert(t);
        }
    }
    for(auto it=s.begin();it!=s.end();++it){
        // cout<<it->u<<"/"<<it->d;
        if(mk(*it)){
            // cout<<" ER";
            s.erase(it);
        }
        // cout<<endl;
    }
    int c=1;
    for(auto it=s.begin();it!=s.end();++it){
        // cout<<it->u<<"/"<<it->d<<endl;
        if(c==n){
            cout<<s.size()<<endl;
            cout<<it->u<<"/"<<it->d<<endl;
            return 0;
        }
        ++c;
    }
    cout<<s.size()<<endl;
    cout<<s.begin()->u<<"/"<<s.begin()->d<<endl;
}
