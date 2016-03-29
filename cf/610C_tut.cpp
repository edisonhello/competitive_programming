#include<bits/stdc++.h>

using namespace std;

short ans[10][515][515];
bool cnt[10];

void build(int n){
    int bign = (1<<(n-1));
    if(cnt[n]){
        return;
        //cout
    }
    else{
        build(n-1);

        for(int i=1;i<=bign;i++){
            for(int j=1;j<=bign;j++){
                ans[n][i][j] = ans[n-1][i][j];
                ans[n][i+bign][j+bign] = ans[n][i+bign][j] = ans[n-1][bign-i+1][j];
                // = ans[n][i+bign][j];//
                ans[n][i][j+bign] =!ans[n][i][j];//
            }
        }
    }
}

int main(){
    int n;cin>>n;

    cnt[0] = cnt[1] = cnt[2] = 1;
    ans[0][1][1] = 1;
    ans[1][1][2] = 1;
    ans[2][3][2] = ans[2][4][2] = ans[2][2][3] = ans[2][4][3] = ans[2][2][4] = ans[2][3][4] = 1;

    build(n);

    int bign = (1<<n);
    for(int i=1;i<=bign;i++){
        for(int j=1;j<=bign;j++){
            if(ans[n][j][i]==1){
                cout<<"+";
            }
            else if(ans[n][j][i]>=2){
                cout<<"-";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
