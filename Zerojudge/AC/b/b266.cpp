#include<bits/stdc++.h>
using namespace std;

int n,m;


int main(){
    int q; cin>>n>>m>>q;
    vector<vector<int>> a(13,vector<int>(13,0));
    vector<vector<int>> b(13,vector<int>(13,0));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];
    stack<int> st; while(q--){int t; cin>>t; st.push(t);}
    while(st.size()){
        int op=st.top(); st.pop();
        if(op){
            for(int i=0,j=n-1;i<n;++i,--j){
                for(int k=0;k<m;++k)b[j][k]=a[i][k];
            }
        }
        else{
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    b[m-1-j][i]=a[i][j];
                }
            }
            swap(n,m);
        }
        swap(a,b);
        for(int i=0;i<13;++i)for(int j=0;j<13;++j)b[i][j]=0;
    }
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
