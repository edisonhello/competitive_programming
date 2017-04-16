#include<bits/stdc++.h>
using namespace std;

int l[51111],r[51111],w[51111],n;
int seg[1123456];
vector<int> num;

void jizz(){
    int mx=0,now=0;
    for(int i=0;i<n;++i)seg[l[i]]+=w[i];
    for(int i=0;i<1111111;++i){
        now+=seg[i];
        now=max(now,0);
        mx=max(mx,now);
    }
    cout<<mx<<endl;
    exit(0);
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>l[i]>>r[i]>>w[i]; ++r[i];
        num.push_back(l[i]);
        num.push_back(r[i]);
    }
    if(n>100)jizz();
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=0;i<n;++i){
        l[i]=lower_bound(num.begin(),num.end(),l[i])-num.begin();
        r[i]=lower_bound(num.begin(),num.end(),r[i])-num.begin();
    }

    int m=(int)num.size(),mx=0;
    for(int i=0;i<m;++i){
        for(int j=i;j<m;++j){
            int nw=0;
            for(int p=0;p<n;++p){
                if(l[p]<=j && i<r[p])nw+=w[p];
            }
            // cout<<i<<" "<<j<<" "<<nw<<endl;
            mx=max(mx,nw);
        }
    }
    cout<<mx<<endl;
}
