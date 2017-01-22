#include<cstdio>
#include<deque>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define ll unsigned int

struct s{int i;ll h;};

deque<s> mn,mx;
ll h;
vector<pair<int,int>> ans;

int main(){
    int n,m;ll k;
    scanf("%d%d%u",&n,&m,&k);
    // for(int i=1;i<=n;++i)cin>>h[i];
    scanf("%u",&h);
    mn.push_front({1,h});
    mx.push_front({1,h});
    for(int l=1,r=1;l<n;){
        if(r<n)scanf("%u",&h);
        ++r;
        if(r<=n){
            while(mn.size() && mn.front().h>=h)mn.pop_front();
            while(mx.size() && mx.front().h<=h)mx.pop_front();
            mn.push_front({r,h});
            mx.push_front({r,h});
        }
        if(r-l>=m){
            ++l;
            while(mn.size() && mn.back().i<l)mn.pop_back();
            while(mx.size() && mx.back().i<l)mx.pop_back();
        }
        if(mx.back().h-mn.back().h==k){
            ans.push_back({l,min(r,n)});
        }
    }
    printf("%u\n",ans.size());
    for(auto p:ans){
        printf("%d %d\n",p.first,p.second);
    }
}
