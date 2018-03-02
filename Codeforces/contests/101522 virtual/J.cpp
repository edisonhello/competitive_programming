#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=3000000000000000000ll;

ll BRS[201][201][201][3];
// string ans[212][212][212];
bitset<3> v[201][201][201];


ll go(int b,int r,int s,int prv){
    // cout<<b<<" "<<r<<" "<<s<<" "<<prv<<endl;
    if(prv>=0 && v[b][r][s][prv])return BRS[b][r][s][prv];
    v[b][r][s][prv]=1;
    if(b==1 && !r && !s && prv!=0){
        return BRS[b][r][s][prv]=1;
    }
    if(!b && r==1 && !s && prv!=1){
        return BRS[b][r][s][prv]=1;
    }
    if(!b && !r && s==1 && prv!=2){
        return BRS[b][r][s][prv]=1;
    }
    // if(b+r<s-1 || b+s<r-1 || s+r<b-1)return cout<<"dead"<<endl,0;
    if(b && prv!=0){
        BRS[b][r][s][prv]=min(BRS[b][r][s][prv]+go(b-1,r,s,0),mod);
    }
    if(r && prv!=1){
        BRS[b][r][s][prv]=min(BRS[b][r][s][prv]+go(b,r-1,s,1),mod);
    }
    if(s && prv!=2){
        BRS[b][r][s][prv]=min(BRS[b][r][s][prv]+go(b,r,s-1,2),mod);
    }
    // cout<<b<<" "<<r<<" "<<s<<" "<<prv<<" is "<<BRS[b][r][s][prv]<<endl;
    return BRS[b][r][s][prv];
}

string ans;

void gans(int b,int r,int s,ll k,int prv){
    // cout<<"gans: "<<b<<" "<<r<<" "<<s<<" "<<k<<" "<<prv<<endl;
    if(!b && !r && !s)return;
    if(b && BRS[b-1][r][s][0]>=k && prv!=0){
        ans+='B';
        gans(b-1,r,s,k,0);
        return;
    }
    else if(b && prv!=0)k-=BRS[b-1][r][s][0];
    if(r && BRS[b][r-1][s][1]>=k && prv!=1){
        ans+='R';
        gans(b,r-1,s,k,1);
        return;
    }
    else if(r && prv!=1)k-=BRS[b][r-1][s][1];
    if(s && BRS[b][r][s-1][2]>=k && prv!=2){
        ans+='S';
        gans(b,r,s-1,k,2);
        return;
    }
    else if(s && prv!=2)k-=BRS[b][r][s-1][2];
    // cout<<"dead at "<<b<<" "<<r<<" "<<s<<" "<<k<<endl;
}

int main(){
    int b,r,s; ll k;
    cin>>b>>r>>s>>k;
    go(b,r,s,0);
    go(b,r,s,1);
    go(b,r,s,2);
    /* for(int i=0;i<=b;++i){
        for(int j=0;j<=r;++j){
            for(int k=0;k<=s;++k){
                for(int p=0;p<3;++p){
                    cout<<"BRS "<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<BRS[i][j][k][p]<<endl;
                }
            }
        }
    } */
    BRS[0][0][0][0]=BRS[0][0][0][1]=BRS[0][0][0][2]=1;
    gans(b,r,s,k,-1);
    if(ans.size()<b+r+s)cout<<"None"<<endl;
    else cout<<ans<<endl;
}
