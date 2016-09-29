#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m;
ll C;
ll a[1005];
ll rec[1005];
ll ans[1005];
int mn;
bool useful[1005];

bool CHK(int took){
    long long c=1;
    for(int i=0;i<took;i++){
        c*=rec[i];
    }
    return !(c%C);
}

ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int dfs(int now,long long c,int took){
    // cout<<"dfs now:"<<now<<endl;
    if(c%C==0 && CHK(took)){
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
        if(a[i]>1 && useful[i]){
            rec[took]=i;
            dfs(i,c*a[i],took+1);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin>>m>>C;
    int T1=0;
    memset(useful,1,sizeof(useful));
    for(int i=0;i<m;i++){
        cin>>a[i];
        if(a[i]%C==0){
            T1=i;
        }
        else if(gcd(a[i],C)==1){
            useful[i]=0;
        }
    }

    if(T1){
        cout<<"1\n"<<T1<<"\n";
        return 0;
    }

    mn=m+5;

    dfs(-1,1l,0);

    if(mn!=m+5){
        cout<<mn<<'\n';
        for(int i=0;i<mn;i++){
            if(i)cout<<' ';
            cout<<ans[i];
        }
        cout<<'\n';
    }
    else{
        cout<<"-1\n";
    }
}
