#include<bits/stdc++.h>
using namespace std;

int a[1000005],b[1000005];
bitset<1000005> v;
vector<int> storage[1000005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int bal=0;
    for(int i=1;i<=n;++i){
        if(v[i])continue;
        int cnt=1;
        int j=a[i];
        v[i]=1;
        vector<int> lm;
        lm.push_back(i);
        while(j!=i){
            v[j]=1;
            ++cnt;
            lm.push_back(j);
            j=a[j];
        }
        if(cnt&1){
            vector<int> shun(cnt);
            int wei=0;
            for(int i=0;i<cnt;++i){
                shun[wei]=lm[i];
                wei+=2;
                if(wei>=cnt)wei-=cnt;
            }
            shun.push_back(shun[0]);
            for(int i=1;i<=cnt;++i){
                b[shun[i-1]]=shun[i];
            }
        }
        else{
            auto &v=storage[cnt];
            if(v.size()){
                v.push_back(v[0]);
                // lm.push_back(lm[0]);
                for(int i=0;i<cnt;++i){
                    b[v[i]]=lm[i];
                    b[lm[i]]=v[i+1];
                }
                --bal;
                v.clear();
            }
            else{
                storage[cnt]=lm;
                ++bal;
            }
        }
    }
    if(bal)cout<<-1;
    else for(int i=1;i<=n;++i)cout<<b[i]<<" ";
    cout<<endl;
}
