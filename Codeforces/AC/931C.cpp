#include<bits/stdc++.h>
using namespace std;


int a[100005];
int b[100005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    auto mxit=max_element(a,a+n),mnit=min_element(a,a+n);
    if(*mxit-*mnit==2){
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;++i){
            if(a[i]==*mnit)++cnt0;
            else if(a[i]==*mxit)++cnt2;
            else ++cnt1;
        }
        int open=cnt1/2*2;
        int close=min(cnt0,cnt2)*2;
        if(open>close){
            cnt0+=cnt1/2;
            cnt2+=cnt1/2;
            cnt1%=2;
            cout<<n-open<<endl;
            for(int i=0;i<cnt0;++i)cout<<*mnit<<" ";
            for(int i=0;i<cnt1;++i)cout<<(*mnit)+1<<" ";
            for(int i=0;i<cnt2;++i)cout<<*mxit<<" ";
            cout<<endl;
        }
        else{
            int dta=min(cnt0,cnt2);
            cnt1+=dta*2;
            cnt0-=dta;
            cnt2-=dta;
            cout<<n-close<<endl;
            for(int i=0;i<cnt0;++i)cout<<*mnit<<" ";
            for(int i=0;i<cnt1;++i)cout<<(*mnit)+1<<" ";
            for(int i=0;i<cnt2;++i)cout<<*mxit<<" ";
            cout<<endl;
        }
    }
    else{
        cout<<n<<endl;
        for(int i=0;i<n;++i)cout<<a[i]<<" ";
        cout<<endl;
    }
}
