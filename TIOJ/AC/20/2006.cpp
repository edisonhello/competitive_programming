#include<bits/stdc++.h>
using namespace std;

int opi[444];
int cpy[444];
int main(){
    int n,m; cin>>n>>m; m=3*m+1;
    for(int i=0,t;i<m;++i)cin>>t,++opi[t];
    queue<int> ans;
    for(int gt=1;gt<=n;++gt){
        for(int ey=1;ey<=n;++ey){
            for(int i=1;i<=n;++i)cpy[i]=opi[i]; ++cpy[gt]; 
            if(cpy[ey]<2)continue;
            cpy[ey]-=2;
            int ok=1;
            for(int i=1;i<=n-2;++i){
                if(cpy[i]<0){ok=0; break;}
                if(cpy[i]%3!=0){
                    cpy[i+1]-=cpy[i]%3;
                    cpy[i+2]-=cpy[i]%3;
                    cpy[i]=cpy[i]/3*3;
                }
            }
            if(cpy[n-1]<0 || cpy[n]<0)ok=0;
            for(int i=1;i<=n;++i)cpy[i]%=3;
            if(cpy[n-1] || cpy[n])ok=0;
            if(ok){ans.push(gt); break;}
        }
    }
    if(ans.empty())cout<<"NO"<<endl;
    else while(ans.size()){
        cout<<ans.front()<<" "; ans.pop();
    }
}
