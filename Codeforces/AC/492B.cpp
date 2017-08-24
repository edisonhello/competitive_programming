#include<bits/stdc++.h>
using namespace std;

inline int rit(){
int a;scanf("%d",&a);return a;
}

#define fr(x) for(int i=0;i<x;i++)

int main(){
    int n=rit(),d=rit();
    vector<int> lt;
    fr(n){int t=rit();lt.push_back(t);}
    /*lt.push_back(0);
    lt.push_back(d);*/
    sort(lt.begin(),lt.end());
    double mx=0;
    for(int i=1;i<n;i++){
            //cout<<"jizz "<<lt[1]-lt[0];
        if(lt[i]-lt[i-1]>mx){
            mx=lt[i]-lt[i-1];
        }
    }

    mx /= 2;

    if(lt[0]>mx){
        mx = lt[0];
    }
    if(d-lt.back()>mx){
        mx = d-lt.back();
    }

    printf("%.10lf\n",mx);

}
