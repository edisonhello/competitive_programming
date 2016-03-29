#include<bits/stdc++.h>

using namespace std;

#define for(x) for(int i=0;i<x;i++)

inline int rit(){
    int k;scanf("%d",&k);return k;
}

int main(){
    int n=rit();
    vector<int> j;
    for(n){int t = rit();j.push_back(t);}
    sort(j.begin(),j.end());
    //reverse(j.begin(),j.end());
    for(j.size())printf("%d ",j[i]);
}
