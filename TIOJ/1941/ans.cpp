// by pr3pony
#include<bits/stdc++.h>
using namespace std;

multiset<int> st;

int main(){
    int n;cin>>n;
    while(n--){
        int l,r;cin>>l>>r;
        auto it=st.upper_bound(r);
        if(it!=st.end())st.erase(it);
        st.insert(l);
    }
    cout<<st.size()<<endl;
    return 0;
}
