#include<iostream>
#include<algorithm>
using namespace std;
struct b{int p,f;} a[1005];
bool cmp_f(const b &_,const b &__){
    return _.f>__.f;
}
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].p>>a[i].f;
    }
    sort(a,a+n,cmp_f);
    int now=0,fin=0;
    for(int i=0;i<n;++i){
        now+=a[i].p;
        fin=max({fin,now+a[i].f});
    }
    cout<<fin<<endl;
}
