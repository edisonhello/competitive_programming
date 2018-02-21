#include<bits/stdc++.h>
using namespace std;

vector<int> a;

int main(){
    srand(time(0));
    int n=1000000;
    for(int i=0;i<n;++i)a.push_back(i+1);
    random_shuffle(a.begin(),a.end());
    for(int i=0;i<n;++i){
        cout<<a[i];
        if(i==n-1){cout<<endl; continue;}
        else{
            int t=rand()%3+1;
            while(t--)cout<<" ";
        }
    }
    random_shuffle(a.begin(),a.end());
    for(int i=0;i<n;++i){
        cout<<a[i];
        if(i==n-1){cout<<endl; continue;}
        else{
            int t=rand()%3+1;
            while(t--)cout<<" ";
        }
    }
}
