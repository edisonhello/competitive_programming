#include"grader.h"

#include<bits/stdc++.h>
using namespace std;

namespace C1{
    int sum;
}

int r,c,h[5004][204],v[5004][204];

vector<pair<int,int>> G[404];

void init(int __r,int __c,int __h[5000][200],int __v[5000][200]){
    // cout<<"in init"<<endl;
    r=__r; c=__c;
    for(int i=0;i<5000;++i)for(int j=0;j<200;++j)h[i][j]=__h[i][j];
    for(int i=0;i<5000;++i)for(int j=0;j<200;++j)v[i][j]=__v[i][j];

    if(c==1)for(int i=0;i<r;++i)C1::sum+=v[i][0];
}

void changeH(int p,int q,int w){
    // cout<<"in changeH"<<endl;
    if(c==1)C1::sum-=h[p][q];
    h[p][q]=w;
    if(c==1)C1::sum+=w;
}

void changeV(int p,int q,int w){
    // cout<<"in changeV"<<endl;
    if(c==1)C1::sum-=v[p][q];
    v[p][q]=w;
    if(c==1)C1::sum+=w;
}

int escape(int s,int t){
    // cout<<"in escape"<<endl;
    if(c==1)return C1::sum;
    return 42;
}
