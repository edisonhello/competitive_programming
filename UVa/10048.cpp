#include<bits/stdc++.h>

using namespace std;


int n,l,q,mp[105][105];
vector<int> r;
/*
int go(int now,int dis,int mx){
        printf("now = %d, dis = %d, now mx %d\n",now,dis,mx);

}
*/

int main(){int t=0;
    while(cin>>n>>l>>q && n){
            t++;


        for(int i=1;i<=l;i++){
            for(int j=1;j<=l;j++){
                mp[i][j] = (1<<10/**/);
                if(i==j){
                    mp[i][j] = 0;
                }
            }
        }
        //format

        //for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<mp[i][j]<<" ";}cout<<endl;}

        for(int i=0;i<l;i++){
            int a,b,c;cin>>a>>b>>c;
            mp[a][b] = mp[b][a] = c;
        }
        //input

        //for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<mp[i][j]<<" ";}cout<<endl;}

        for(int k=1;k<=l;k++){
            for(int i=1;i<=l;i++){
                for(int j=1;j<=l;j++){
                    mp[i][j] = min( mp[i][j] , max( mp[i][k], mp[k][j] ));
                }
            }
        }

        //for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<mp[i][j]<<" ";}cout<<endl;}

        cout<<"Case #"<<t<<endl;
        while(q--){
            int a,b;cin>>a>>b;

            int ans = mp[a][b];

            if(mp[a][b] == (1<<10/**/) || mp[a][b] == 0){
                cout<<"no path"<<endl;
                continue;
            }
            cout<<mp[a][b]<<endl;
        }
    }
}
