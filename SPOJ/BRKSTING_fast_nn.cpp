#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1234];
ll b[1234],c[1234];
bitset<1234> v[1234];

int main(){
    int n,m; while(cin>>n>>m){
        for(int i=0;i<m;++i)cin>>a[i]; a[m]=n;
        for(int i=m;i>0;--i)b[i]=a[i]-a[i-1]; ++m; b[0]=a[0];
        // cout<<"new array: ";
        // for(int i=0;i<m;++i)cout<<b[i]<<" "; cout<<endl;
        ll ans=0;
        ll *prv=b,*now=c;
        while(m>1){
            // cout<<"now m: "<<m<<endl;
            int firstk=-1;
            for(int i=0;i<m-2;++i){
                if(prv[i]<prv[i+2]){
                    firstk=i;
                    break;
                }
            }
            if(firstk==-1)firstk=m-2;
            // cout<<"firstk: "<<firstk<<endl;
            ll newval=prv[firstk]+prv[firstk+1];
            int insertafter=-1;
            for(int i=firstk-1;i>=0;--i){
                if(prv[i]>newval){
                    insertafter=i;
                    break;
                }
            }
            // cout<<"newval, insertafter: "<<newval<<" "<<insertafter<<endl;
            memset(now,0,sizeof(int)*1000);
            int ptr=-1;
            for(int i=0;i<m;++i){
                if(i>insertafter)now[++ptr]=newval,insertafter=99999999;
                if(i==firstk || i==firstk+1)continue;
                now[++ptr]=prv[i];
                // cout<<"i,ptr = "<<i<<" "<<ptr<<endl;
            }
            m=ptr+1;
            ans+=newval;
            swap(prv,now);
            // cout<<"new array: ";
            // for(int i=0;i<m;++i)cout<<prv[i]<<" "; cout<<endl;
        }
        cout<<ans<<endl;
    }
}
