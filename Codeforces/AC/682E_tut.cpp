#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> pt[5005];

long long area(long long x1,long long y1,long long x2,long long y2){
    return x1*y2-x2*y1;
}

long long area(int x,int y,int z){
    return area(pt[y].first-pt[x].first,pt[y].second-pt[x].second,pt[z].first-pt[x].first,pt[z].second-pt[x].second);
}

int main(){
    int n; long long s; cin>>n>>s;
    for(int i=1;i<=n;++i)cin>>pt[i].first>>pt[i].second;
    int i1=1,i2=2,i3=3;
    while(1){
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(area(i,i2,i3)>area(i1,i2,i3))i1=i,++cnt;
            if(area(i1,i,i3)>area(i1,i2,i3))i2=i,++cnt;
            if(area(i1,i2,i)>area(i1,i2,i3))i3=i,++cnt;
        }
        if(!cnt)break;
    }
    // cout<<i1<<" "<<i2<<" "<<i3<<endl;
    cout<<pt[i1].first+(pt[i3].first-pt[i2].first)<<" "<<pt[i1].second+(pt[i3].second-pt[i2].second)<<endl;
    cout<<pt[i3].first+(pt[i2].first-pt[i1].first)<<" "<<pt[i3].second+(pt[i2].second-pt[i1].second)<<endl;
    cout<<pt[i2].first+(pt[i1].first-pt[i3].first)<<" "<<pt[i2].second+(pt[i1].second-pt[i3].second)<<endl;
}
