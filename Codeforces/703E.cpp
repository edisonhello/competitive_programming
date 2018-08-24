#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m;
ll C;
ll a[1005];
int rec[1005];
int ans[1005];
int mn;

ll G(ll a,ll b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int dfs(int now,long long c,int took){
    // cout<<"dfs now:"<<now<<endl;
    if(c%C==0){
        if(took<mn){
            mn=took;
            for(int i=0;i<took;i++){
                ans[i]=rec[i];
            }
        }
        mn=min(mn,took);
        return 0;
    }
    for(int i=now+1;i<m;i++){
        // cout<<"considering "<<i<<endl;
        if(a[i]>1 && G((C/c),a[i])!=1){
            rec[took]=i;
            dfs(i,c*a[i],took+1);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin>>m>>C;
    bool has1=0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        if(a[i]==1){
            has1=1;
        }
    }

    mn=m+5;

    dfs(-1,1l,0);

    if(mn!=m+5){
        cout<<mn<<'\n';
        for(int i=0;i<mn;i++){
            if(i)cout<<' ';
            cout<<ans[i]+1;
        }
        cout<<'\n';
    }
    else if(has1 && C==1){
        cout<<"1\n1\n";
    }
    else{
        cout<<"-1\n";
    }
}
