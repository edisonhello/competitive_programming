#include<bits/stdc++.h>
using namespace std;

pair<int,int> tms[    1000];
int main(){
    int n,m; while(cin>>n>>m){memset(tms,0,sizeof(tms));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int h,m; scanf("%d:%d",&h,&m);
            tms[j].first+=60*h+m;
            tms[j].second=j;
        }
    }
    sort(tms,tms+m);
    for(int i=0;i<m;++i)cout<<tms[i].second+1<<" "<<tms[i].first<<endl;
}}
