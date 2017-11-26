#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a,poss; cin>>n>>k>>a; poss=(n+1)/(a+1);
    set<int> st; st.insert(0); st.insert(n+1);
    cin>>n; for(int i=1;i<=n;++i){
        int x; cin>>x; auto it=st.lower_bound(x); auto it2=it; --it;
        poss=poss-(*it2-*it)/(a+1)+(*it2-x)/(a+1)+(x-*it)/(a+1);
        st.insert(x);
        if(poss<k)return cout<<i<<endl,0;
    } cout<<-1<<endl;
}
