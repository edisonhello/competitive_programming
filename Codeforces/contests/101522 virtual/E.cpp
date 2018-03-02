#include<bits/stdc++.h>
using namespace std;
#define ld long double


set<int> pos[100005];
int numb[200005];

int main(){
    int n,r; cin>>n>>r;
    ld prv=0;
    for(int i=1;i<r;++i){
        int x,y,cx,cy; cin>>x>>y>>cx>>cy;
        pos[cx].insert(x);
        pos[cy].insert(y);
        numb[x]=cx;
        numb[y]=cy;
        if(cx==cy)prv=max(prv,(ld)cx);
    }
    int unk=0;
    ld choose_2_sum=0,choose_1_opt=0,choose_2_chs=0,iknowboth=0;
    for(int i=1;i<=2*n;++i)if(!numb[i])++unk;
    for(int i=int(prv)+1;i<=n;++i){
        if(pos[i].size()==2u)iknowboth=max(iknowboth,(ld)i);
        else if(pos[i].size()==1u){
            choose_1_opt=max(choose_1_opt,prv*(unk-1)/unk+(ld)i/unk);
        }
        else{
            choose_2_sum+=max((ld)i,prv);
            choose_2_chs+=2.0/unk/(unk-1);
        }
    }
    cout<<fixed<<setprecision(10)<<
        max(max(iknowboth,prv),
        max(choose_1_opt,
            choose_2_sum/unk/(unk-1)*2+prv*(1.0-choose_2_chs)))
    <<endl;
    // cout<<prv<<" "<<choose_1_opt<<" "<<choose_2_sum<<endl;
}
