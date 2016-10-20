#include<bits/stdc++.h>
using namespace std;
int n,q,mp[22][22],rdp[22][22][22][22],ldp[22][22][22][22],rdpt[22][22][22][22],ldpt[22][22][22][22];
void read(),init(),dp(),query();
int main(){
    ios_base::sync_with_stdio(0);
    read();
    init();
    dp();
    query();
}

void dp(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            memset(rdpt,0,sizeof(rdpt));
            memset(ldpt,0,sizeof(ldpt));
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    rdpt[k][l][k][l]=mp[k][l];
                    ldpt[k][l][k][l]=mp[k][l];
                    if(i==k&&j==l){
                        rdpt[k][l][k][l]=0;
                        ldpt[k][l][k][l]=0;
                    }
                }
            }
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    for(int m=k;m<=n;m++){
                        for(int o=l;o<=n;o++){
                            if(i==m&&j==o){
                                if(m>k&&l>o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o-1],rdpt[k][l][m-1][o]});
                                }
                                else if(m>k){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m-1][o]});
                                }
                                else if(l>o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o-1]});
                                }
                            }
                            else{
                                if(m>k&&l>o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o-1],rdpt[k][l][m-1][o]})+mp[m][o];
                                }
                                else if(m>k){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m-1][o]})+mp[m][o];
                                }
                                else if(l>o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o-1]})+mp[m][o];
                                }
                            }
                        }
                    }
                    for(int m=k;m<=n;m++){
                        for(int o=l;o>0;o--){
                            if(i==m&&j==o){
                                if(m>k&&l<o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o+1],rdpt[k][l][m-1][o]});
                                }
                                else if(m>k){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m-1][o]});
                                }
                                else if(l<o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o+1]});
                                }
                            }
                            else{
                                if(m>k&&l<o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o+1],rdpt[k][l][m-1][o]})+mp[m][o];
                                }
                                else if(m>k){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m-1][o]})+mp[m][o];
                                }
                                else if(l<o){
                                    rdpt[k][l][m][o]=min({rdpt[k][l][m][o+1]})+mp[m][o];
                                }
                            }
                        }
                    }
                    for(int m=1;m<=n;m++){
                        for(int o=1;o<=n;o++){
                            rdp[k][l][m][o]=min({rdp[k][l][m][o],rdpt[k][l][m][o]});
                            ldp[k][l][m][o]=min({ldp[k][l][m][o],ldpt[k][l][m][o]});
                        }
                    }
                }
            }
        }
    }
}

void query(){
    int qs;cin>>qs;
    int x1,y1,x2,y2;
    while(qs--){
        cin>>x1>>y1>>x2>>y2;
        if(x1<x2){
            swap(x1,x2);swap(y1,y2);
        }
        if(y2>y1){
            cout<<rdp[]
        }
        else{

        }
    }
}

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;j<=n;k++){
                for(int l=1;l<=n;l++){
                    rdp[i][j][k][l]=1000000;
                    ldp[i][j][k][l]=1000000;
                    // if(i==k&&j==l){
                    //     rdp[i][j][k][l]=mp[i][j];
                    //     ldp[i][j][k][l]=mp[i][j];
                    // }
                }
            }
        }
    }
}

void read(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>mp[i][j];
        }
    }
}
