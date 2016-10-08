#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],fx[1005],stat[1005];
bool infx[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int nowcome=1;
    int nowwantpt=0;
    int fxz=0,fxpt=0;;
    int stt=0;
    while(nowwantpt<n){
        while(fxz<m && nowcome<=n){
            fx[fxpt]=nowcome;
            infx[nowcome]=1;
            ++fxz;++fxpt;++nowcome;
        }
        if(infx[a[nowwantpt]]){
            --fxz;
            ++nowwantpt;
            continue;
        }
        if(stat[stt-1]==a[nowwantpt]){
            ++nowwantpt;--stt;
            continue;
        }
        while(a[nowwantpt]!=nowcome && nowcome<=n){
            stat[stt]=nowcome;
            ++stt;++nowcome;
        }
        if(nowcome>n){
            cout<<"no\n";
            return 0;
        }
        if(a[nowwantpt]==nowcome){
            ++nowcome;++nowwantpt;
        }
    }
    cout<<"yes\n";
}
