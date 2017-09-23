#include<iostream>
#include<assert.h>
#include<algorithm>
#define ll long long
using namespace std;
struct tc{ll t;char w;} a[3];
bool cmp(const tc &a,const tc &b){return a.t>b.t;}
int main(){
    while(cin>>a[0].t>>a[1].t>>a[2].t){
        a[0].w='A',a[1].w='B',a[2].w='C';
        sort(a,a+3,cmp);
        if(a[0].t>a[1].t+a[2].t)cout<<a[0].w<<endl;
        else if(a[1].t>a[2].t)cout<<a[1].w<<endl;
        else cout<<a[2].w<<endl;
    }
}
