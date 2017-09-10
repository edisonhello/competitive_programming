#include<bits/stdc++.h>
using namespace std;
int main(){
    string tree;
    while(cin>>tree){
        int leaves=0; for(char c:tree)if(c=='*')++leaves;
        int dep=1,mxdep=1; for(char c:tree)if(c=='(')++dep,mxdep=max(mxdep,dep);else if(c==')')--dep;
        assert(dep==1); int yuan[100000]={0},mxy=0; for(char c:tree)if(c=='(')++yuan[dep++];else if(c=='*')++yuan[dep];else mxy=max(mxy,yuan[dep]),yuan[dep]=0,--dep;
        for(int i=1;i<tree.length();++i) mxy=max(mxy,yuan[i]);
        cout<<leaves<<" "<<mxdep<<" "<<mxy<<endl;
    }
}
