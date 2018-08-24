#include<bits/stdc++.h>
using namespace std;
int disf0[5005],disfo[5005];

#ifdef WEAK
int getDistance(int i,int j){
    cout<<"Q "<<i<<" "<<j<<endl;
    int t; cin>>t; return t;
}
#else
#include"rail.h"
#endif

#define get getDistance
void findLocation(int n,int first,int location[],int stype[]){
    for(int i=1;i<n;++i)disf0[i]=get(0,i);
    int o=min_element(disf0+1,disf0+n)-disf0; 
    stype[0]=1; stype[o]=2;
    location[o]=disf0[o];
    for(int i=1;i<n;++i)if(i!=o)disfo[i]=get(o,i);
    vector<int> L,R;
    for(int i=1;i<n;++i)if(i!=o){
        if(disfo[i]<disf0[o])location[i]=location[o]-disfo[i],stype[i]=1;
        else if(disf0[i]<disfo[i])R.push_back(i);
        else L.push_back(i);
    }
    // cout<<"o: "<<o<<endl;
    {
        set<int,greater<int>> t1pos; t1pos.insert(location[0]);
        sort(L.begin(),L.end(),[&](const int &a,const int &b){ return disfo[a]<disfo[b]; });
        int la=0;
        for(int i:L){
            int d=get(i,la);
            int pospos=location[la]+d;
            int llpos=*t1pos.lower_bound(pospos);
            bool gor=1;
            if(llpos==pospos)gor=0;
            else{
                if(disfo[i]==location[o]-llpos+pospos-llpos);
                else gor=0;
            }
            // cout<<"Ling "<<i<<" , gor: "<<gor<<endl;
            // cout<<"llpos: "<<llpos<<" , pospos: "<<pospos<<endl;
            // cout<<"disfo[i]: "<<disfo[i]<<endl;
            if(gor)location[i]=location[la]+d,stype[i]=2;
            else location[i]=location[o]-disfo[i],stype[i]=1,la=i,t1pos.insert(location[i]);
        }
    }
    {
        set<int> t2pos; t2pos.insert(location[o]);
        sort(R.begin(),R.end(),[&](const int &a,const int &b){ return disf0[a]<disf0[b]; });
        int la=o;
        for(int i:R){
            // cout<<"R working "<<i<<" cur la: "<<la<<endl;
            int d=get(i,la);
            // cout<<"d: "<<d<<" disf0[i]: "<<disf0[i]<<" , disf0[la]: "<<disf0[la]<<endl;
            int pospos=location[la]-d;
            int rrpos=*t2pos.lower_bound(pospos);
            bool gol=1;
            if(rrpos==pospos)gol=0;
            else{
                if(disf0[i]==rrpos+(rrpos-pospos));
                else gol=0;
            }
            if(gol)location[i]=location[la]-d,stype[i]=1;
            else location[i]=location[0]+disf0[i],stype[i]=2,la=i,t2pos.insert(location[i]);
        }
    }

    for(int i=0;i<n;++i)location[i]+=first;

    // cout<<"location: "; for(int i=0;i<n;++i)cout<<location[i]<<" "; cout<<endl;
    // cout<<"stype: "; for(int i=0;i<n;++i)cout<<stype[i]<<" "; cout<<endl;
}

#ifdef WEAK
int lo[4152454],st[2555554];
int main(){
    int n=4;

    findLocation(n,2,lo,st);

    cout<<"location: "; for(int i=0;i<n;++i)cout<<lo[i]<<" "; cout<<endl;
    cout<<"stype: "; for(int i=0;i<n;++i)cout<<st[i]<<" "; cout<<endl;
}
#endif
