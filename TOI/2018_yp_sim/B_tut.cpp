#include<bits/stdc++.h>
using namespace std;

int a[1000006],rightend[1000006],rightside[1000006],leftend[1000006],leftside[1000006],ismemberc[1000006],ismemberd[1000006],cv[1000006],dv[1000006],cntl[1000006],cntr[1000006],samecnt;
int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    int c,d; cin>>c>>d;
    for(int i=1;i<=c;++i){
        cin>>cv[i];
        ismemberc[cv[i]]=i;
    }
    for(int i=1;i<=d;++i){
        cin>>dv[i];
        ismemberd[dv[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(ismemberc[a[i]]==0)continue;
        if(ismemberc[a[i]]==1){
            rightend[1]=i;
        }
        else rightend[ismemberc[a[i]]]=rightend[ismemberc[a[i]]-1];
        if(ismemberc[a[i]]==c)rightside[i]=rightend[c];
        // cout<<"rightside["<<i<<"]: "<<rightside[i]<<endl;
    }
    for(int i=n;i>=1;--i){
        if(ismemberd[a[i]]==0)continue;
        if(ismemberd[a[i]]==1){
            leftend[1]=i;
        }
        else leftend[ismemberd[a[i]]]=leftend[ismemberd[a[i]]-1];
        if(ismemberd[a[i]]==d)leftside[i]=leftend[d];
        // cout<<"leftside["<<i<<"]: "<<leftside[i]<<endl;
    }
    for(int i=1;i<=n;++i)++cntr[a[i]];
    int L=0,R=1;
    vector<int> ans;
    for(int i=1;i<=n;++i){
        if(ismemberc[a[i]]==c && ismemberd[a[i]]==d){
            if(!leftside[i] || !rightside[i])continue;
            while(R<=leftside[i]){
                --cntr[a[R]];
                if(cntr[a[R]]==0 && cntl[a[R]])--samecnt;
                ++R;
            }
            while(L+1<rightside[i]){
                ++L;
                ++cntl[a[L]];
                if(cntl[a[L]]==1 && cntr[a[L]])++samecnt;
            }
            // cout<<"LR: "<<L<<" "<<R<<endl;
            if(samecnt)ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    if(ans.empty())ans.push_back(-1);
    for(int i:ans){
        cout<<i;
        if(i==ans.back())cout<<endl;
        else cout<<" ";
    }
}
