#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    set<pair<int,int>> pt;
    for(int i=0;i<=min(1,n);++i){
        for(int j=0;j<=min(1,m);++j){
            pt.insert({i,j});
        }
    }
    for(int i=n;i>=max(n-1,0);--i){
        for(int j=m;j>=max(m-1,0);--j){
            pt.insert({i,j});
        }
    }
    pt.insert({0,m});
    pt.insert({n,0});
    double len=0;
    pair<int,int> a1,a2,a3,a4;
    for(auto i=pt.begin();i!=pt.end();++i){
        for(auto j=pt.begin();j!=pt.end();++j){
            if(j==i)continue;
            for(auto k=pt.begin();k!=pt.end();++k){
                if(k==j)continue;
                if(k==i)continue;
                for(auto l=pt.begin();l!=pt.end();++l){
                    if(l==k)continue;
                    if(l==j)continue;
                    if(l==i)continue;

                    #define d(a,b,c,d) sd(a,b)+sd(b,c)+sd(c,d)
                    #define sd(a,b) sqrt(pow(a->first-b->first,2)+pow(a->second-b->second,2))

                    if(d(i,j,k,l)>len){
                        len=d(i,j,k,l);
                        tie(a1,a2,a3,a4)=tie(*i,*j,*k,*l);
                    }
                }
            }
        }
    }
    #define p(x) cout<<x.first<<" "<<x.second<<endl
    p(a1),p(a2),p(a3),p(a4);
}
