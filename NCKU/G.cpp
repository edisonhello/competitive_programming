#include<bits/stdc++.h>
using namespace std;

int cnt[44],c[44];;

bool check(){
        vector<int> v;
    for (int i = 0; i < 44; ++i) if (cnt[i] >= 3)  v.push_back(i);
    for (int s = 0; s < (1 << v.size()); ++s) {
        vector<int> c(cnt, cnt + 44);
        for (int j = 0; j < v.size(); ++j) if (s >> j & 1) c[v[j]] %= 3;
        for(int i=0;i<=6;++i){
            while(c[i]>0 && c[i+1]>0 && c[i+2]>0){
                --c[i]; --c[i+1]; --c[i+2];
            }
        }
        for(int i=9;i<=15;++i){
            while(c[i]>0 && c[i+1]>0 && c[i+2]>0){
                --c[i]; --c[i+1]; --c[i+2];
            }
        }
        for(int i=18;i<=24;++i){
            while(c[i]>0 && c[i+1]>0 && c[i+2]>0){
                --c[i]; --c[i+1]; --c[i+2];
            }
        }
        int le=0;
        for(int i=0;i<=33;++i)if(c[i]%3)++le;
        if(!le)return 1;
    }
    return 0;
}

int main(){
    for(int i=1;i<=17;++i){
        int t; cin>>t; ++cnt[t];
    }
    bool ok=0;
    for(int i=0;i<=33;++i){
        if(cnt[i]<2)continue;
        cnt[i]-=2;
        if(check())ok=1;
        cnt[i]+=2;
    }
    cout<<ok<<endl;
}
