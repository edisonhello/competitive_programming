#include<bits/stdc++.h>
using namespace std;
int main(){
    string tree;
    while(cin>>tree){
        if(tree=="*"){cout<<"1 1 0\n";continue;}
        int leaves=0,depth=1,ary[100005]={0},nd=1,ma=0;
        for(char c:tree){
            if(c=='*'){
                leaves++;
                ary[nd]++;
            }
            if(c=='('){
                ary[nd]++;
                nd++;
                depth=max(depth,nd);
            }
            if(c==')'){
                nd--;
            }
        }
        for(int i=0;i<depth+2;++i){
            ma=max(ma,ary[i]);
        }
        cout<<leaves<<" "<<depth<<" "<<ma<<endl;
    }
}
