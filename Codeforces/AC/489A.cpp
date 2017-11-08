#include<bits/stdc++.h>
using namespace std;

int a[3333],b[3333];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i],b[i]=a[i];
    sort(b,b+n);
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
            for(int j=i+1;j<n;++j){
                if(a[j]==b[i]){
                    q.emplace(i,j);
                    swap(a[i],a[j]);
                    break;
                }
            }
        }
    }
    cout<<q.size()<<endl;
    while(q.size()){
        cout<<q.front().first<<" "<<q.front().second<<endl;
        q.pop();
    }
}
