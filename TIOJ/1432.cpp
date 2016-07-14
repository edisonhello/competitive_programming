#include<iostream>
#include<vector>
#define m (l+r)/2
using namespace std;
vector<int> s;
int n,w,t;




bool chk(int y,int st){
    for(int i=st;i<s.size() && s[i]>=y;i++){
        if(s[i]==y)return 1;
        return chk(y-s[i],i+1);
    }
    return 0;
}

int bs(int l,int r){
    if(l==r)return r;

    if(chk(m,0)){
        return bs(l,m);
    }
    else{
        return bs(m+1,r);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin>>n>>w && n && w){
        t = 0;
        s.clear();
        s.resize(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
            t += s[i];
        }

        reverse(s.begin(),s.end());

        int r = bs(0,t);
        cout<<r<<'\n';
    }
}
