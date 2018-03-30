// copy from UVa 406
#include<bits/stdc++.h>
using namespace std;

bitset<1000> np;
vector<int> p;
void init(){
    p.push_back(1);
    for(int i=2;i<1000;++i){
        if(!np[i])p.push_back(i);
        for(int j=1;p[j]*i<1000;++j){
            np[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    // for(int i:p)cout<<i<<" ";
}

int main(){
    init();
    int n,c; while(cin>>n>>c){
        int cnt=upper_bound(p.begin(),p.end(),n)-p.begin();
        set<int> ans;
        if(cnt&1){
            for(int i=cnt/2,j=0;i<cnt && j<c;++j,++i)ans.insert(p[i]);
            for(int i=cnt/2,j=0;i>=0 && j<c;++j,--i)ans.insert(p[i]);
        }
        else{
            for(int i=cnt/2,j=0;j<c && i<cnt;++j,++i)ans.insert(p[i]);
            for(int i=cnt/2-1,j=0;i>=0 && j<c;++j,--i)ans.insert(p[i]);
        }
        cout<<n<<" "<<c<<":";
        for(int i:ans){
            cout<<" "<<i;
        }
        cout<<endl<<endl;
    }
}
