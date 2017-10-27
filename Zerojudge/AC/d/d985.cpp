#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;for(int tr=0;tr<n;++tr){
        int m;cin>>m;
        int be=99999999,t=0;
        for(int i=0;i<m;++i){
            int a,b;cin>>a>>b;
            b+=a*60;
            be=min(be,b);
            t+=b;
        }
        t/=m;
        if(tr)cout<<endl;
        cout<<"Track "<<tr+1<<":\nBest Lap: "<<be/60<<" minute(s) "<<be%60<<" second(s).\nAverage: "<<t/60<<" minute(s) "<<t%60<<" second(s).\n";
    }
}
