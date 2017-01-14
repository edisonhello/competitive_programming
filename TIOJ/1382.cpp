#include<iostream>
using namespace std;
#include<vector>

vector<int> v;

int main(){
    int n;while(cin>>n){
        v.clear();
        for(int i=0;i<n;++i)v.push_back(i);

        int index=-1;
        for(int i=0,t;i<n;++i){
            cin>>t;index+=t;
            if(index>=(int)v.size())index%=(int)v.size();
            if(i)cout<<" ";cout<<v[index]+1;
            v.erase(v.begin()+index);
            --index;
        }
        cout<<endl;
    }
}
