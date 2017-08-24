#include<bits/stdc++.h>
using namespace std;
int app[30];
char rep;
int p1,p2;
int main(){
    ios_base::sync_with_stdio(0);
    memset(app,0xff,sizeof(app));
    string in;cin>>in;
    app[in[0]-'A']=0;
    for(int i=1;i<27;++i){
        if(app[in[i]-'A']!=-1){
            rep=in[i];
            p1=app[in[i]-'A'];
            p2=i;
        }
        app[in[i]-'A']=i;
        if(in[i]==in[i-1]){
            cout<<"Impossible\n";
            return 0;
        }
    }
    deque<char> dq;
    for(char c:in)dq.push_back(c);
    while((p1+p2)/2!=13){
        if((p1+p2)/2<13){
            dq.push_front(dq.back());
            dq.pop_back();
            ++p1,++p2;
        }
        if((p1+p2)/2>13){
            dq.push_back(dq.front());
            dq.pop_front();
            --p1,--p2;
        }
    }
    // cout<<p1<<" "<<p2<<endl;
    if(p2-13>13-p1){
        for(int i=0;i<13;++i){
            if(dq.front()==rep){
                dq.pop_front();--i;
                continue;
            }
            cout<<dq.front();dq.pop_front();
        }
        cout<<endl;
        for(int i=0;i<13;i++){
            cout<<dq.back();dq.pop_back();
        }
        cout<<endl;
    }
    else{
        for(int i=0;i<13;++i){
            cout<<dq.front();dq.pop_front();
        }
        cout<<endl;
        for(int i=0;i<13;i++){
            if(dq.back()==rep){
                dq.pop_back();--i;
                continue;
            }
            cout<<dq.back();dq.pop_back();
        }
        cout<<endl;
    }
}
