#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
    int r,c;while(cin>>r>>c){
        int xx[8]={1,1,1,0,-1,-1,-1,0};
        int yy[8]={1,0,-1,-1,-1,0,1,1};
        memset(a,0,sizeof(a));
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(j-1)cout<<' ';
                if(a[i][j]){
                    cout<<"X";
                    continue;
                }
                else{
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        if(a[i+xx[k]][j+yy[k]]){
                            cnt++;
                        }
                    }
                    cout<<cnt;
                }
            }
            cout<<'\n';
        }
    }
}
