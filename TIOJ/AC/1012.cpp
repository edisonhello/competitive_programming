#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> want;
    queue<int> left;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        want.push_back(t-1);
        left.push(i);
    }

    stack<int> buf;

    for(int i=0;i<n;i++){
        //printf("now i=%d\n",i);
        while(1){
            //printf("loop\n");
            if(left.size() && want[i]==left.front()){
                left.pop();
                //printf("want[i=%d]=left.front=%d\n",i,want[i]);
                break;
            }
            if(buf.size() && buf.top()==want[i]){
                //printf("buf.top()=want[i=%d]=%d\n",i,want[i]);
                buf.pop();
                break;
            }
            if(buf.size()<m){
                buf.push(left.front());
                //printf("buf.push left.front()=%d\n",left.front());
                left.pop();
                continue;
            }
            //cout<<"jizz"<<endl;
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
