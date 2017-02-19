#include<iostream>
#include<assert.h>
#include<cmath>
using namespace std;
#include<set>

set<int> st;
int mp(int b,int n,int a=1){
    while(n){
        if(n&1)a=a*b;
        b*=b;
        n>>=1;
    }
    return a;
}
int pro(int n){
    int cnt=0,tn=n;
    while(tn)tn/=10,++cnt;
    int ans=0;
    while(n){
        ans+=mp(n%10,cnt);
        n/=10;
    }
    return ans;
}
void init(){
    for(int i=1;i<1000005;++i){
        if(pro(i)==i){
            st.insert(i);
        }
    }
}

int main(){
    int n,m;
    init();
    while(cin>>n>>m){
        auto it1=lower_bound(st.begin(),st.end(),n);
        auto it2=lower_bound(st.begin(),st.end(),m+1);
        if(it1==it2)cout<<"none"<<endl;
        else{
            while(it1!=it2){
                cout<<(*it1)<<" ";
                ++it1;
            }
            cout<<endl;
        }
    }
}
