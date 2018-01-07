#include<bits/stdc++.h>
using namespace std;

int a[1000006];
int main(){
    int n; while(cin>>n){
        memset(a,0,sizeof(a));
        int lll=1000000,rrr=0;
        while(n--){
            int l,r; cin>>l>>r;
            ++a[l]; --a[r];
            rrr=max(rrr,r);
            lll=min(lll,l);
        }
        int now=0,ans=0;
        for(int i=lll;i<=rrr;++i){
            now+=a[i];
            if(now>0)++ans;
        }
        cout<<ans<<endl;
    }
}
