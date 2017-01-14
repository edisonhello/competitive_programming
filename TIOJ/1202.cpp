#include<vector>
#include<iostream>
using namespace std;

struct bu{
    int l,h,r;
    bu():l(0),r(0),h(0);
}

vector<bu> a,b;
int n;

int main(){
    while(cin>>n,n){
        a.clear(),b.clear();
        a.resize(n),b.resize(n);
        for(int i=0,q,w,e;i<n;++i){
            cin>>q>>w>>e;
            a.push_back({q,w,e});
        }
    }
}
