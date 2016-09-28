#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int n;
    do n=rand()%80+1;while(n<1);
    // cout<<"gen,n="<<n<<endl;
    bool app[99]={0};
    int cnt=0;
    stringstream ss;
    while(cnt<n){
        int gt=rand()%n+1;
        if(app[gt])continue;
        app[gt]=1;
        // cout<<gt<<" ";
        ss<<gt;
        cnt++;
    }
    string s;
    ss>>s;
    cout<</*endl<<*/s<<endl;
}
