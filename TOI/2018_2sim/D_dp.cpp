#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
ll a[300005];
ll dp[300058],pre[300005];

ll calc(int l,int r){
    if(r-l+1<k)1ll<<60;
    int midl=(l+r)/2-1, midr=(l+r+1)/2+1;
    midl=max(midl,l); midr=min(midr,r);
    ll rt=1ll<<60;
    for(int i=midl;i<=midr;++i){
        ll nw=pre[r]-pre[i]-a[i]*(r-i)+a[i]*(i-l)-(pre[i-1]-pre[l-1]);
        if(nw<rt){
            rt=nw;
        }
    }
    return rt;
}

struct item{
    int l,r,cf;
};

void printdq(deque<item> dq){
    for(auto i:dq){
        cout<<"(["<<i.l<<","<<i.r<<"]:"<<i.cf<<") ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
//    for(int i=1;i<=n;++i)cout<<i<<":"<<a[i]<<endl;
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];

    deque<item> dq;
    dq.push_back({k,n,0});

    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;

    for(int i=k,useable=1;i<=n-k+1;++i,++useable){
        dp[i]=dp[dq.front().cf]+calc(dq.front().cf+1,i);
//        cout<<"dp["<<i<<"]: "<<dp[i]<<" , come from "<<dq.front().cf<<endl;
        ++dq.front().l;
        if(dq.front().l>dq.front().r)dq.pop_front();

        while(dq.size()){
            ll orig=dp[dq.back().cf]+calc(dq.back().cf+1,dq.back().l);
            ll pk=dp[useable]+calc(useable+1,dq.back().l);

//            cout<<"useable "<<useable<<" is fighting "<<endl;

            if(pk<=orig){
//                cout<<"beat "<<dq.back().l;
                dq.pop_back();
            }
            else{
                ll worth=dp[dq.back().cf]+calc(dq.back().cf+1,dq.back().r);
                ll pk=dp[useable]+calc(useable+1,dq.back().r);

//                cout<<"try beat right "<<dq.back().r<<endl;
                if(useable==317){
//                    cout<<"ans to right: "<<pk<<endl;
//                    cout<<"ans to 652: "<<dp[useable]+calc(useable+1,652)<<endl;
//                    cout<<"worth: "<<worth<<endl;
                }

                if(pk>worth)break;

//                cout<<"hope! try binary search"<<endl;

                int L=dq.back().l,R=dq.back().r;
                while(R>L){
                    int mid=(L+R)>>1;
                    ll cc=dp[dq.back().cf]+calc(dq.back().cf+1,mid);
                    ll pk=dp[useable]+calc(useable+1,mid);
                    if(pk>cc)L=mid+1;
                    else R=mid;
                }
                dq.back().r=L-1;
                break;
            }
        }


        if(dq.size() && dq.back().r==n){
//            cout<<"use "<<useable<<" is useless"<<endl;
        }
        else{
            int LL=dq.empty()?i+1:dq.back().r+1;
//            cout<<"use "<<useable<<" get new left: "<<LL<<endl;
            dq.push_back({LL,n,useable});
        }

//        printdq(dq);
    }

    dp[n]=1ll<<60;
    int fincf=-1;
    for(int i=n-k;i>=0;--i){
        ll nw=dp[i]+calc(i+1,n);
        if(dp[n]>nw){
            dp[n]=nw;
            fincf=i;
        }
    }
    cout<<dp[n]<<endl;
//    cout<<"fincf: "<<fincf<<endl;
}

