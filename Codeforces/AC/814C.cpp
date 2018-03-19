#include<bits/stdc++.h>
using namespace std;

int ansrec[1555][333];
int get(int n,string &s,int x,char c){
    if(ansrec[x][c])return ansrec[x][c];
    int &ans=ansrec[x][c];
    int L=0,R=-1,nrp=0;
    for(;L<n;){
        while(R+1<n){
            ++R;
            if(s[R]!=c)++nrp;
            if(nrp>x)break;
            ans=max(ans,R-L+1);
        }
        if(s[L]!=c)--nrp;
        ++L;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    int q; cin>>q; while(q--){
        int x; cin>>x;
        char c; cin>>c;
        cout<<get(n,s,x,c)<<'\n';
    }
}
