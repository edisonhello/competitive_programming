#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        vector<int> j;
        for(int i=0;i<3;i++){int a;cin>>a;j.push_back(a);}
        sort(j.begin(),j.end());
        cout<<j[1]<<endl;
    }
}

/*http://acm.hust.edu.cn/vjudge/contest/view.action?cid=109378#problem/A*/
