#include<bits/stdc++.h>
using namespace std;

bool ok(int n,int m,int mx){
    for(int i=mx;i>=1;--i){
        if(m>n)swap(n,m);
        if(n<i)return 0;
        n-=i;
    }
    return 1;
}

int main(){
    int n,m; cin>>n>>m;
    int L=0,R=100000;
    while(L<R){
        int mid=(L+R+1)>>1;
        if(ok(n,m,mid))L=mid;
        else R=mid-1;
    }
    vector<int> a,b;
    vector<int> *aa=&a,*bb=&b;
    while(L>0){
        if(m>n){
            swap(n,m);
            swap(aa,bb);
        }
        aa->push_back(L);
        n-=L;
        --L;
    }
    cout<<a.size()<<endl;
    for(int i:a)cout<<i<<" "; cout<<endl;
    cout<<b.size()<<endl;
    for(int i:b)cout<<i<<" "; cout<<endl;
    

}
