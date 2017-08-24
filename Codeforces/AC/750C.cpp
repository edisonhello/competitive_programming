#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> hst;

int main(){
    int n;cin>>n;
    hst.resize(n);
    for(int i=0;i<n;++i)cin>>hst[i].X>>hst[i].Y;
    int L=-99999999,R=99999999;
    for(int i=0;i<n;++i){
        if(hst[i].Y==2){
            R=min({1899,R});
            L+=hst[i].X;
            R+=hst[i].X;
        }
        else{
            L=max({L,1900});
            L+=hst[i].X;
            R+=hst[i].X;
        }
        // cout<<L<<" "<<R<<endl;
        if(R<L){cout<<"Impossible\n";return 0;}
    }
    if(R>66666666){
        cout<<"Infinity\n";
        return 0;
    }
    cout<<R<<endl;
}
