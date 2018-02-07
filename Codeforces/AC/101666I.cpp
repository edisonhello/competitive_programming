#include<bits/stdc++.h>
using namespace std;

int n,m;
int dpv[123][123][3],clr[123][123];
bitset<3> vdp[123][123];

int get(int y1,int x1,int y2,int x2){
    // cout<<"get "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" = "<<clr[x2][y2]+(x1&&y1?clr[x1-1][y1-1]:0)-(x1?clr[x1-1][y2]:0)-(y1?clr[x2][y1-1]:0)<<endl;
    return clr[x2][y2]+(x1&&y1?clr[x1-1][y1-1]:0)-(x1?clr[x1-1][y2]:0)-(y1?clr[x2][y1-1]:0);
}

int dp(int p,int q,int player){
    if(p==-1 || q==m)return 0;
    if(vdp[p][q][player])return dpv[p][q][player];
    // cout<<"dp "<<p<<" "<<q<<" "<<player<<endl;
    int &ndp=dpv[p][q][player];
    ndp=-878787;
    if(player==1){
        for(int i=q+1;i<=m;++i){
            ndp=max(ndp,get(q,0,i-1,p)-dp(p,i,2));
        }
    }
    else{
        for(int i=p-1;i>=-1;--i){
            ndp=max(ndp,get(q,i+1,m-1,p)-dp(i,q,1));
        }
    }
    vdp[p][q][player]=1;
    // cout<<"dp "<<p<<" "<<q<<" "<<player<<" is "<<ndp<<endl;
    return ndp;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            clr[i][j]=((i+j)&1?-1:1);
            if(i)clr[i][j]+=clr[i-1][j];
            if(j)clr[i][j]+=clr[i][j-1];
            if(i&&j)clr[i][j]-=clr[i-1][j-1];
            // cout<<clr[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp(n-1,0,1)<<endl;
}
