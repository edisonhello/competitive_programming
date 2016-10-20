#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[30];
int b[30];
ll f[25];
int main(){
    int ts;cin>>ts;
    f[0]=f[1]=1;
    for(int i=2;i<22;++i){
        f[i]=f[i-1]*i;
    }
    while(ts--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        string s;cin>>s;
        bool odd=0;
        ll fst=1;
        int n=0,tot=0;
        if((int)s.length()==1){
            cout<<"1\n";
            goto next;
        }
        for(char c:s){
            ++a[c-'a'];
        }
        for(int i=0;i<30;++i){
            if(a[i]&1){
                if(odd){
                    cout<<"0\n";
                    goto next;
                }
                odd=1;
            }
            b[i]=(a[i]>>1);
        }
        sort(b,b+30,greater<int>());
        for(;n<30;n++){
            tot+=b[n];
            if(b[n]==0)break;
        }
        if(tot==0){
            cout<<"0\n";
            goto next;
        }
        fst*=f[tot];
        for(int i=0;i<30;++i){
            fst/=f[b[i]];
        }
        cout<<fst<<'\n';
        next:;
    }
}
