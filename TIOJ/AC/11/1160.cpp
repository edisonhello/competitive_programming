#include<iostream>
#include<utility>
#include<map>

using namespace std;

map<int,int> m;
int mxcnt,mxa,cnt;

int main(){
    int in,now;
    while(cin>>in && in){
        now=++m[in];
        if(now>mxcnt){
            mxcnt=now;
            mxa=in;
        }
        else if(now==mxcnt){
            mxa=min(in,mxa);
        }
        cout<<mxcnt<<" "<<mxa<<endl;
    }
}
