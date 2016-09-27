#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sw=0,sl=0;
    vector<int> ss;
    while(n--){
        int s;
        cin>>s;
        if(s>0)sw++;
        else sl++;
        s=abs(s);
        ss.push_back(s);
    }
    sort(ss.begin(),ss.end());
    double avg=0.0;
    for(int i=1;i<(int)ss.size()-1;i++){
        avg+=(double)ss[i];
    }
    // cout<<avg/(double)(ss.size()-2)<<endl;
    cout<<"Average time: ";
    printf("%.3f",avg/(double)(ss.size()-2));
    cout<<" sec(s).\n";
    cout<<"Winning rate: ";
    printf("%.3f",100.0*(double)sw/(double)(sw+sl));
    cout<<" %.\n";
}
