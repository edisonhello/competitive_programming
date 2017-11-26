#include<bits/stdc++.h>
using namespace std;

int tp[1002];
int main(){
    set<int> st;
    int n; cin>>n; for(int i=1;i<=n;++i){
        string s; int x; cin>>s>>x;
        if(s=="+")st.insert(x),tp[i]=tp[i-1]+1;
        else if(st.find(x)==st.end()){for(int j=i-1;j>=0;--j)++tp[j]; tp[i]=tp[i-1]-1;}
        else st.erase(x),tp[i]=tp[i-1]-1;
    }
    int mx=0;
    for(int i=0;i<1002;++i)mx=max(mx,tp[i]);
    cout<<mx<<endl;
}
