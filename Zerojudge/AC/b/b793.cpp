#include<bits/stdc++.h>
using namespace std;

int fst[1010],cst[1010];
int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;++i){
            int prv=0;
            cst[i]=0;
            for(int j=1,t;j<=n;++j){
                cin>>t; if(j==1)fst[i]=t,prv=t;
                else cst[i]+=(t>prv?t-prv:t+n-prv),prv=t;
            }
        }
        int mn=101010104;
        for(int i=1;i<=n;++i){
            int val=0;
            for(int j=1;j<=n;++j){
                int thisfirst=i+j-1; thisfirst>n?thisfirst-=n:0;
                val=max(val,cst[j]+(fst[j]>=thisfirst?fst[j]-thisfirst:fst[j]+n-thisfirst));
            }
            mn=min(mn,val);
        }
        cout<<mn<<endl;
    }
}
