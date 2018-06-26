#include<bits/stdc++.h>
using namespace std;
#define lock _my_lock

int n,m;
int _dp[1000006][4][5][2]; // [ unlock, lock to up, lock to down ] [ -2, -1, 0, 1, 2 ][ L, P ]

enum Status{ unlock ,lock, lockup, lockdown };
enum Flower{ L, P };

int &dp(int pos,Status s,int prefix,Flower f){
    return _dp[pos][s][prefix + 2][f];
} 

int main(){
    cin>>n>>m;
    string s; cin>>s;
    dp(1,unlock, 1,L)=dp(1,unlock,-1,P)=1;
    for(int i=2;i<=n;++i){
        dp(i,unlock,-1,L) = 0;
        dp(i,unlock,-1,P) = dp(i-1,unlock, 0,L);
        dp(i,unlock, 0,L) = dp(i-1,unlock, 1,L);
        dp(i,unlock, 0,P) = dp(i-1,unlock,-1,P);
        dp(i,unlock, 1,L) = dp(i-1,unlock, 0,P);
        dp(i,unlock, 1,P) = 0;

        dp(i,lock,-1,L) = 0;
        dp(i,lock,-1,P) = dp(i-1,lock, 0,L) + dp(i-1,lock, 0,P)
                        + dp(i-1,unlock, 0,P);
        dp(i,lock, 0,L) = dp(i-1,lock,-1,P);
        dp(i,lock, 0,P) = dp(i-1,lock, 1,L);
        dp(i,lock, 1,L) = dp(i-1,lock, 0,L) + dp(i-1,lock, 0,P)
                        + dp(i-1,unlock, 0,L);
        dp(i,lock, 1,P) = 0;

        dp(i,lockup, 0,L) = 0;
        dp(i,lockup, 0,P) = dp(i-1,lockup, 1,L) + dp(i-1,lockup, 1,P);
        dp(i,lockup, 1,L) = dp(i-1,lockup, 0,P);
        dp(i,lockup, 1,P) = dp(i-1,lockup, 2,L);
        dp(i,lockup, 2,L) = dp(i-1,lockup, 1,L) + dp(i-1,lockup, 1,P)
                          + dp(i-1,unlock, 1,L);
        dp(i,lockup, 2,P) = 0;

        dp(i,lockdown, 0,L) = dp(i-1,lockdown,-1,L) + dp(i-1,lockdown,-1,P);
        dp(i,lockdown, 0,P) = 0;
        dp(i,lockdown,-1,L) = dp(i-1,lockdown,-2,P);
        dp(i,lockdown,-1,P) = dp(i-1,lockdown, 0,L);
        dp(i,lockdown,-2,L) = 0;
        dp(i,lockdown,-2,P) = dp(i-1,lockdown,-1,L) + dp(i-1,lockdown,-1,P)
                            + dp(i-1,  unlock,-1,P);
        for(int j=0;j<4;++j)for(int k=0;k<5;++k)for(int z=0;z<2;++z)while(_dp[i][j][k][z]>=m)_dp[i][j][k][z]-=m;
        for(int j=0;j<4;++j)for(int k=0;k<5;++k)for(int z=0;z<2;++z){
            printf("dp[%d][%d][%d][%d]=%d\n",i,j,k,z,_dp[i][j][k][z]);
        }
    }
    // int npre=0,premn=0,premx=0
    Status locked=unlock;
    int nowpre=0,ans=0;
#define add(x) ((ans=(ans+(x)>=m?ans+(x)-m:ans+(x))))
    for(int i=1;i<=n;++i){
        char c=s[i-1];
        if(c=='L')++nowpre;
        else --nowpre;
        if(nowpre==2)locked=lockup;
        else if(nowpre==-2)locked=lockdown;

        if(c=='L');
        else{
            if(locked==unlock){
                for(int z=-2;z<=2;++z){
                    add(dp(n+1-i,unlock,z,L));
                    add(dp(n+1-i,lock,z,L));
                    add(dp(n+1-i,lockup,z,L));
                    add(dp(n+1-i,lockdown,z,L));
                }
            }
            else{
                for(int z=-2;z<=2;++z){
                    add(dp(n-i,locked,z,L));
                }
            }
            cout<<"when i = "<<i<<" , ans inc to "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
}
