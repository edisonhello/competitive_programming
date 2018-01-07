#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; while(cin>>n){
        vector<int> p;
        while(n--){
            int t; cin>>t; p.push_back(t);
        }
        sort(p.begin(),p.end());
        int hi=-1;
        for(int i:p)if(i<60)hi=max(hi,i);
        int lo=101;
        for(int i:p)if(i>59)lo=min(lo,i);
        for(int i=0;i<p.size();++i)cout<<p[i]<<" \n"[i==p.size()-1];
        hi==-1?cout<<"best case"<<endl:cout<<hi<<endl;
        lo==101?cout<<"worst case"<<endl:cout<<lo<<endl;
    }
}
