#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
vector<int> a;
int n;

void merge(int l,int r){
    int k=l,e=mid+1;
    vector<int> tmp;
    while(k<=mid && e<=r){
        if(a[k]<a[e]){
            tmp.push_back(a[k++]);
        }
        else{
            tmp.push_back(a[e++]);
        }
    }
    while(k<=mid){
        tmp.push_back(a[k++]);
    }
    while(e<=r){
        tmp.push_back(a[e++]);
    }
    for(int i=l,j=0;i<=r;i++,j++){
        a[i]=tmp[j];
    }

// cout<<"after merge "<<l<<" "<<r<<" result ";
// for(int i=0;i<n;i++)cout<<a[i];cout<<endl;

    return;
}

void mergesort(int l,int r){
    // cout<<"mergesort "<<l<<" "<<r<<endl;
    if(l==r){
        return;
    }
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,r);
}

void sort_(){
    mergesort(0,n-1);
}

int main(){
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort_();

    int mex=0;
    for(int i=0;i<n;i++){
        if(a[i]>mex){
            mex++;
        }
    }
    cout<<mex+1<<endl;
}
