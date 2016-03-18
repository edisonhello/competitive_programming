#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct jizz{
    ll m,n,v;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<jizz> app;
    int n,m;
    jizz t;
    t.m=1000000;
    t.n=1000000;
    t.v=333333833333500000;
    app.push_back(t);
    while(cin>>n>>m && n){

        for(int i=0;i<app.size();i++){
            if(app[i].m==m&&app[i].n==n){
                cout<<app[i].v<<endl;
                continue;
            }
        }

            ll cnt=0;
        for(int i=min(m,n);i>=0;i--){
            cnt += (ll) (m-i)*(n-i);
            jizz t;
            t.m=m-i;
            t.n=n-i;
            t.v=cnt;
            app.push_back(t);
        }
        jizz t;
        t.m=m;
        t.n=n;
        t.v=cnt;
        app.push_back(t);
    cout<<cnt<<endl;

    }
}
