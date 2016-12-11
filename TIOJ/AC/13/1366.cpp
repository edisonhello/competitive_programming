#include<iostream>
#include<algorithm>
using namespace std;
struct _{
    string s;
    int v;
};
bool cmp(const _ &a,const _ &b){
    return a.v<b.v;
}

int n;
_ a[100005];

int main(){
    while(cin>>n){
        for(int i=0;i<n;++i){
            cin>>a[i].s;a[i].v=0;
            for(int j=0;j<(int)a[i].s.length();++j){
                a[i].v+=a[i].s[j]-'0';
            }
        }
        stable_sort(a,a+n,cmp);
        for(int i=0;i<n;++i){
            if(i)cout<<" ";
            cout<<a[i].s;
        }
        cout<<endl;
    }
}
