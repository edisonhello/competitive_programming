#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rit(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
#define pb push_back
using namespace std;

ll dp[18][100005];
ll pp[18][100005];


int trace[10][10];

int main(){
    int ts;rit(ts);while(ts--){
        int n,m,x,a;rit(n),rit(m),rit(x),rit(a);
        for(int i=1;i<=n+1;++i){
            for(int j=1;j<=m;++j){
            	if(i==n+1)dp[i][j]=0;
                else dp[i][j]=-(1ll<<48);
                if(i==n+1)continue;
                pp[i][j]=0;
                rll(pp[i][j]);
                pp[i][j]+=pp[i][j-1];
            }
        }
        //for(int j=x;j<=x+a && j<=m;++j)dp[n][j]=(pp[1][j]-pp[1][x-1]);
        //for(int j=x;j>=x-a && j>0;--j)dp[n][j]=(pp[1][x]-pp[1][j-1]);
        // for(int i=1;i<=m;++i)cout<<dp[1][i]<<" ";cout<<endl;

        for(int i=n;i>=1;i--){
			deque<int> idx;
            for(int j=1;j<=m;++j){
				while(!idx.empty()&&dp[i+1][idx[idx.size()-1]]-pp[i][idx[idx.size()-1]-1]<dp[i+1][j]-pp[i][j-1]) idx.pop_back();
            	idx.pb(j);
                while(!idx.empty()&&j-idx.front()>a) idx.pop_front();
                int k=idx.front();
				dp[i][j]=dp[i+1][k]+pp[i][j]-pp[i][k-1];

				//printf("%d ",dp[i][j]);
            }
            //printf("       ");
            idx.clear();
            for(int j=m;j>0;j--){
				while(!idx.empty()&&dp[i+1][idx[idx.size()-1]]+pp[i][idx[idx.size()-1]]<dp[i+1][j]+pp[i][j]) idx.pop_back();
				idx.pb(j);
            	while(!idx.empty()&&idx.front()-j>a) idx.pop_front();
                int k=idx.front();

                //if(dp[i][j]<dp[i+1][k]+pp[i][k]-pp[i][j-1]) printf("%d ",k);
                //else printf("0 ");
                //printf("%d\n",idx.size());

				dp[i][j]=max(dp[i][j],dp[i+1][k]+pp[i][k]-pp[i][j-1]);

				//printf("%d ",dp[i+1][k]+pp[i][k]-pp[i][j-1]);
			}

			//puts("");

        }
        printf("%lld\n",dp[1][x]);

        /*for(int i=1;i<=2;i++)
        {
        	for(int j=1;j<=5;j++){
        		printf("%d ",trace[i][j]);
			}
			puts("");
		}*/
    }
}
