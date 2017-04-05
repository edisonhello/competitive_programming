#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#define ll long long
#define ld long double

using namespace std;

const int Z=900720143;
int a[100005],rept[100005],dp[100005][25],predp[100005][25];
map<int,int> lsa;

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        int N,K;cin>>N>>K;
        {
            for(int i=1;i<=N;++i)a[i]=0,rept[i]=0;
            for(int i=0;i<=N;++i)for(int j=0;j<=K;++j){dp[i][j]=predp[i][j]=0;}
            lsa.clear();
        }
        {
            for(int i=1;i<=N;++i){
                cin>>a[i];
                auto it=lsa.find(a[i]);
                if(it==lsa.end()){
                    lsa[a[i]]=i;
                    rept[i]=rept[i-1];
                }
                else{
                    rept[i]=max({it->second,rept[i-1]});
                    it->second=i;
                }
            }
        }
        {
            // cout<<"rept: ";for(int i=1;i<=N;++i)cout<<rept[i]<<" ";cout<<endl;
            dp[0][0]=1;
            for(int i=1;i<=N;++i){
                for(int k=1;k<=K;++k){
                    if(k==1 && rept[i]==0)dp[i][k]++;
                    dp[i][k]+=(predp[i-1][k-1]-predp[(rept[i]-1)>0?rept[i]-1:0][k-1]);
                    if(dp[i][k]>=Z)dp[i][k]%=Z;
                    else if(dp[i][k]<0)dp[i][k]=dp[i][k]%Z+Z;
                    predp[i][k]=predp[i-1][k]+dp[i][k];
                    if(predp[i][k]>=Z)predp[i][k]%=Z;
                    else if(predp[i][k]<0)predp[i][k]=predp[i][k]%Z+Z;
                }
            }
        }
        {/*
            cout<<"dp table: "<<endl;
            for(int i=1;i<=N;++i){
                for(int j=1;j<=K;++j){
                    cout<<setw(2)<<dp[i][j]<<"("<<setw(2)<<predp[i][j]<<") ";
                }cout<<endl;
            }
        */}
        cout<<dp[N][K]<<endl;
    }
}
