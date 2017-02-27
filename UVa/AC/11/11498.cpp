#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int n;while(cin>>n,n){
        int x,y;cin>>x>>y;
        while(n--){
            int xx,yy;cin>>xx>>yy;
            if(x==xx || y==yy)cout<<"divisa"<<endl;
            else{
                if(xx-x>0&&yy-y>0)cout<<"NE"<<endl;
                else if(xx-x<0&&yy-y>0)cout<<"NO"<<endl;
                else if(xx-x>0&&yy-y<0)cout<<"SE"<<endl;
                else cout<<"SO"<<endl;
            }
        }
    }
}
