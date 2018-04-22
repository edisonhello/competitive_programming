#include<bits/stdc++.h>
using namespace std;

int a[200005],cnt[200005];
set<pair<int,int>> co;
int use[200005];

int main(){
    int c,n; cin>>c>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)++cnt[a[i]];
    for(int i=1;i<=c;++i)if(cnt[i])co.insert({i,cnt[i]});
    for(int i=0;i<=c;++i){
        auto ptr=co.upper_bound({i,1<<29});
        if(ptr==co.begin())use[i]=-1;
        else --ptr,use[i]=ptr->first;
        // cout<<"use["<<i<<"]: "<<use[i]<<endl;
    }
    for(int gi=2;gi<=c;++gi){
        if(cnt[gi])co.erase({gi,cnt[gi]});
        ++cnt[gi];
        co.insert({gi,cnt[gi]});
        int cle=c;
        int $=1<<29;
        bool u=0;
        while(cle){
            $=min($-1,use[cle]);
            if($<gi && !u && gi<=cle && cnt[gi]==1){
                u=1;
                $=gi;
            }
            if($<1)break;
            auto it=co.upper_bound({$,cnt[$]});
            if(it==co.begin())break;
            --it;
            int u$=min(it->second,cle/it->first)*it->first;
            cle-=u$;
        }
        if(cle)exit((cout<<gi<<endl,0));
        co.erase({gi,cnt[gi]});
        --cnt[gi];
        if(cnt[gi])co.insert({gi,cnt[gi]});
    }

    cout<<"Greed is good"<<endl;
}
