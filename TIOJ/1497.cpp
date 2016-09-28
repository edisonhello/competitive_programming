#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int arr[100005];
vector<int> cnt[200];

char G(int index,int i){
    if(index+i>=n) return 'z'+1;
    else return s[index+i];
}

void radixSort(int i){
    for(int i=0;i<200;i++){
        cnt[i].clear();
    }
    for(int j=0;j<n;j++){
        cnt[G(arr[j],i)].push_back(arr[j]);
        // cout<<"push back "<<arr[j]<<" in cnt of "<<G(arr[j],i)<<endl;
    }
    for(int j=0,k=0;k<n&&j<200;j++){
        for(int l=cnt[j].size()-1;l>=0;l--){
            arr[k++]=cnt[j][l];
        }
    }
}


int main(){
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    for(int i=n-1;i>=0;i--){
        radixSort(i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }
}
