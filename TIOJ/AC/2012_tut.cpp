#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ld eps=1e-9;

struct Solve{
    ld **a,*b;
    Solve(int n){
        a=new ld*[n];
        b=new ld[n];
        for(int i=0;i<n;++i)a[i]=new ld[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>a[i][j];
            }
            cin>>b[i];
        }
        bitset<777> corr;
        int *corrr=new int[n];
        int *permu=new int[n];
        for(int i=0;i<n;++i)permu[i]=i;
        random_shuffle(permu,permu+n);
        for(int iii=0;iii<n;++iii){
            int i=permu[iii];
            int use=-1; ld useval=0;
            for(int j=0;j<n;++j){
                if(abs(a[j][i])>useval && !corr[j]){
                    useval=abs(a[j][i]);
                    use=j;
                }
            }
            corrr[use]=i;
            ld multi=a[use][i];
            corr[use]=1;
            for(int j=0;j<n;++j)a[use][j]/=multi;
            b[use]/=multi;
            for(int jj=0;jj<n;++jj){
                if(jj==use)continue;
                ld decby=a[jj][i];
                for(int j=0;j<n;++j){
                    a[jj][j]-=decby*a[use][j];
                }
                b[jj]-=decby*b[use];
            }
        }
        ld *ans=new ld[n];
        for(int i=0;i<n;++i)ans[corrr[i]]=b[i];
        for(int i=0;i<n;++i){
            cout<<fixed<<setprecision(15)<<ans[i]<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int t; cin>>t; while(t--){
        int n; cin>>n;
        Solve solve(n);
    }
}
