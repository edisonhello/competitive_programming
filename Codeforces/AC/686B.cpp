#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
    vector<pair<ull,ull> > sw;
    ull n;cin>>n;
    vector<ull> a;a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int t=0;t<n*n;t++){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                sw.push_back(make_pair(i,i+1));
                i++;
            }
        }
    }

    for(int i=0;i<(int)sw.size()-1;i++){
        if(sw[i].second+1 == sw[i+1].first){
            sw[i].second = sw[i+1].second;
            sw.erase(sw.begin()+(i+1));
        }
    }

    for(int i=0;i<(int)sw.size();i++){
        cout<<sw[i].first+1<<" "<<sw[i].second+1<<endl;
    }
}
