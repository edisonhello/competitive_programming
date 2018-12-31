#include<bits/stdc++.h>
using namespace std;

#define cu(x) ((x)*(x)*(x))
#define li(x,a,b) if (m==x) { cout<<(a)<<" "<<(b)<<endl; exit(0); }

void walk(int x){
    while(x){
        int y=pow(x,1.0/3);
        x-=cu(y);
        cout<<y<<" ";
    }
    cout<<endl;
}

int get(int x){
    int r=0;
    while(x){
        int y=pow(x,1.0/3);
        x-=cu(y);
        ++r;
    }
    return r;
}

void getans(int m){
    int cnt=-1,ii=-1;
    for(int i=1;i<=m;++i){
        int cc=get(i);
        if(cc>=cnt)cnt=cc,ii=i;
    }
    cout<<cnt<<" "<<ii<<endl;
    exit(0);
}

int main(){
    long long m; cin>>m;
    /* li(1,1,1);
    li(2,2,2);
    li(3,3,3);
    li(4,4,4);
    li(5,5,5);
    li(6,6,6);
    li(7,7,7);
    li(8,7,7);
    li(9,7,7);
    li(10,7,7);
    li(11,7,7);
    li(12,7,7);
    li(13,7,7);
    li(14,7,7);
    li(15,8,15);
    li(16,8,15); */
    walk(m)
    if(m<=10000){
        getans(m);
    }
    /* long long sum=0;
    vector<long long> ans;
    for (long long i=1;;++i) {
        if (sum+i*i*i<=m) {
            sum+=cu(i);
            ans.push_back(i);
        } else break;
    }
    for (int i=int(ans.size())-1;i>=0;--i) {
        if (i==int(ans.size())-1) {
            while (sum-cu(ans.back())+cu(ans.back()+1)<=m) {
                sum=sum-cu(ans.back())+cu(ans.back()+1);
                ++ans.back();
            }
        } else {
            while (sum-cu(ans[i])+cu(ans[i]+1)<=m && ans[i+1]!=ans[i]+1) {
                sum=sum-cu(ans[i])+cu(ans[i]+1);
                ++ans[i];
            }
        }
    }
    cout<<ans.size()<<" "<<sum<<endl; */
}
