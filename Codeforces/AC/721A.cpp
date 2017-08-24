#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    bool last=0;
    int cnt=0;
    vector<int> a;
    while(n--){
        char c; cin>>c;
        bool th=c=='B';
        if(last){
            if(th)++cnt;
            else{
                last=0;
                a.push_back(cnt);
                cnt=0;
            }
        }
        else{
            if(th){
                last=1;
                cnt++;
            }
        }
    }
    if(last)a.push_back(cnt);
    cout<<a.size()<<endl;
    for(int i:a)cout<<i<<" ";
}
