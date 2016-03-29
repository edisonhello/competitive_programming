#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int n;scanf("%d",&n);
    ll ans=0;
    vector<ll> clr;
    clr.resize(n);

    for(int i=0;i<n;i++){
        scanf("%lld",&clr[i]);
    }
    vector<ll> cpy = clr;

    sort(cpy.begin(),cpy.end());


    ans += cpy[0]*n;
    for(int i=0;i<clr.size();i++){
        clr[i] -= cpy[0];
    }

    //find max length
    //find frt
    //find bak
    bool foundfrt=false;
    ll cnt=0,fnt;
    ll mx=-1;
    for(int i=0;i<clr.size();i++){
        if(clr[i]==0){         // printf("when i %d,get fnt %d\n",i,fnt);
            if(!foundfrt){
                fnt = cnt;
                foundfrt = true;
            }
            mx = max(mx,cnt);
            cnt=0;
            continue;
        }
        cnt++;
    }         //  printf("fnt %d",fnt);
    mx = max(mx,fnt+cnt);

    ans+=mx;

    printf("%lld\n",ans);

}
