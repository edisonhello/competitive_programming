#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
const int N=101000;
int n;
struct Q{
    int r,ll,lr;
    void read(){scanf("%d%d%d",&r,&ll,&lr);}
}q[N];
set<int>S;
bool chk(Q &q) {
    int r=q.r;
    S.erase(r);
    auto it1 = S.lower_bound(q.ll);
    auto it2 = S.lower_bound(q.lr+1);
    S.insert(r);
    if(it1 == it2)return false;
    return true;
}
pair<int,int>bad[N];
int solve() {
    int ans=S.size();
    int top=0;
    FOR(i,n)
       if(!chk(q[i]))
            bad[top++]={q[i].lr,q[i].ll};
    sort(bad,bad+top);
    int now=-1;
    if(top==0)return S.size();
    FOR(i,top)
        if(bad[i].Y > now) {
            ans++;
            now=bad[i].X;
        }
    return ans;
}
int main() {
    int T;
    scanf("%d",&T);
    FOR1(w,T) {
        scanf("%d",&n);
        FOR(i,n)q[i].read();
        S.clear();
        FOR(i,n)S.insert(q[i].r);
        printf("%d\n",solve());
    }
    return 0;
}
