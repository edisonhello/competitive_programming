#include<bits/stdc++.h>
using namespace std;

bitset<1002> mp[1002];

int main(){
    int t; cin>>t; while(t--){
        for(int i=0;i<1002;++i)mp[i].reset();
        int a; cin>>a;
        a=max(a,9);
        a=((a-1)/3+1)*3;
        int nx=10,ny=10;
        int ex=(a-9)/3+10;
        while(1){
            cout<<nx<<" "<<ny<<endl;
            int zx,zy; cin>>zx>>zy;
            if(zx==-1)exit(0);
            if(zx==0)break;
            mp[zx][zy]=1;
            if(nx!=ex){
                if(mp[nx-1][ny-1] && mp[nx-1][ny] && mp[nx-1][ny+1]){
                    ++nx;
                }
            }
        }
    }
}
