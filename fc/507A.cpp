#include<bits/stdc++.h>
using namespace std;
struct jizz{
int pos,time;
};bool operator < (const jizz &a,const jizz &b){
    return a.time<b.time;
}

int main(){
    int m,n;cin>>m>>n;
    vector<jizz>a;
    for(int i=0;i<m;i++){
        jizz t;cin>>t.time;
        t.pos=i;
        a.push_back(t);

    }
    sort(a.begin(),a.end());
    int cnt=0;
    for(int i=0;i<m;i++){
        cnt+=a[i].time;

        if(cnt>n){
            cout<<i<<endl;
            for(int ia=0;ia<i;ia++){
                if(ia)cout<<" ";
                cout<<a[ia].pos+1;
            }
            cout<<endl;return 0;
        }
    }cout<<a.size()<<endl;
    for(int i=0;i<m;i++){
        if(i)cout<<" ";
        cout<<i+1;
    }cout<<endl;
}
