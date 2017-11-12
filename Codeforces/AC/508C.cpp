#include<bits/stdc++.h>
using namespace std;
void jizz(){cout<<"-1"<<endl; exit(0);}

map<int,bool> busy;
int fjz[6567];
int main(){
    int m,t,r,ans=0,tptr=0,ling=0; cin>>m>>t>>r;
    for(int i=-1000;i<=1000;++i)busy[i]=0;
    for(int i=0;i<m;++i){
        int tt; cin>>tt;
        while(tptr<tt){
            ++tptr;
            ling-=fjz[tptr];
        }
        int liptr=tptr-1;
        while(ling<r){
            while(busy[liptr])--liptr;
            if(liptr+1+t<=tt)jizz();
            fjz[liptr+1+t]++;
            ling++;
            ans++;
            busy[liptr]=1;
        }
    }
    cout<<ans<<endl;
}
