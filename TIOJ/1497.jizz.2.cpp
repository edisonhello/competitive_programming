#include<bits/stdc++.h>
using namespace std;

int arr[100005];
string s;

bool cmp(const int a,const int b){
    int i=a,j=b;
    for(;max(i,j)<(int)s.length();i++,j++){
        if(s[i]!=s[j]){
            return s[i]<s[j];
        }
    }
    if(j==(int)s.length()) return 0;
    else return 1;
}

int main(){
    cin>>s;
    for(int i=0;i<(int)s.length();i++)arr[i]=i;
    sort(arr,arr+(int)s.length(),cmp);
    for(int i=0;i<(int)s.length();i++){
        cout<<arr[i]<<'\n';
    }
}
