#include<bits/stdc++.h>
using namespace std;
#define ld long double

struct cc{
    ld x,y,r;
    ld ara(){return r*r*3.1415926535;}
} c[1234];

bool ins(cc c1,cc c2){
    return sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2))<=c2.r;
}

int team[1234];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>c[i].x>>c[i].y>>c[i].r;
    sort(c,c+n,[](const cc &a,const cc &b){return a.r>b.r;});
    ld ans=0;
    for(int i=0;i<n;++i){
        int inside1=0;
        int inside2=0;
        for(int j=i-1;j>=0;--j){
            if(team[j]==1 && ins(c[i],c[j]))inside1^=1;
            if(team[j]==2 && ins(c[i],c[j]))inside2^=1;
        }
        if(inside1==0){
            team[i]=1;
            ans+=c[i].ara();
        }
        else if(inside2==0){
            team[i]=2;
            ans+=c[i].ara();
        }
        else{
            team[i]=1;
            ans-=c[i].ara();
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
