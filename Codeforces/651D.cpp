#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,t; cin>>n>>a>>b>>t;
    string s; cin>>s;
    for(char &c:s)c=(c=='w');
    if(t<(s[0]?b:0)+1)return cout<<0<<endl,0;
    if(n==1)return cout<<1<<endl,0;
    int mx=1;
    int left_t=t-(s[0]?b:0)-1,leftptr=n;
    while(left_t>0 && leftptr>=2){
        // cout<<"lptr "<<leftptr<<" and leftt: "<<left_t<<endl;
        if(left_t<=a+(s[leftptr-1]?b:0))break;
        left_t-=a+(s[leftptr-1]?b:0)+1;
        --leftptr; ++mx;
    }
    if(leftptr==1)return cout<<n<<endl,0;
    int rightptr=1;
    // cout<<"before right "<<mx<<endl;
    // cout<<"left side: "<<leftptr<<endl;
    // cout<<"t left: "<<left_t<<endl;
    [=,&mx]()mutable{
        left_t-=(n-leftptr)*a;
            while(left_t>a+(s[rightptr]?b:0)){
                left_t-=a+(s[rightptr]?b:0)+1;
                ++rightptr;
                mx=max(rightptr+n-leftptr,mx);
            }
            // cout<<"l r ptr "<<leftptr<<" "<<rightptr<<endl;
        while(leftptr<n){
            left_t+=a*2+(s[leftptr]?b:0);
            ++leftptr;
            while(left_t>a+(s[rightptr]?b:0)){
                left_t-=a+(s[rightptr]?b:0)+1;
                ++rightptr;
                mx=max(rightptr+n-leftptr,mx);
            }
            // cout<<"l r ptr "<<leftptr<<" "<<rightptr<<endl;
        }    
    }();
    [=,&mx]()mutable{
            while(left_t>2*a+(s[rightptr]?b:0)){
                left_t-=2*a+(s[rightptr]?b:0)+1;
                ++rightptr;
                mx=max(rightptr+n-leftptr,mx);
            }
            // cout<<"l r ptr "<<leftptr<<" "<<rightptr<<endl;
        while(leftptr<n){
            left_t+=a+(s[leftptr]?b:0);
            ++leftptr;
            while(left_t>2*a+(s[rightptr]?b:0)){
                left_t-=2*a+(s[rightptr]?b:0)+1;
                ++rightptr;
                mx=max(rightptr+n-leftptr,mx);
            }
            // cout<<"l r ptr "<<leftptr<<" "<<rightptr<<endl;
        }
    }();
    cout<<mx<<endl;
}
