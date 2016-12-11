#include<iostream>
#include<algorithm>
#include<cmath>
#define ld long double
#define ll long long
using namespace std;
struct pnt{
    int x,y,i;
    pnt(){x=y=0;}
    pnt(int x){this->x=this->y=x;}
    pnt(int x,int y){this->x=x;this->y=y;}
    pnt& operator=(const pnt &a){this->x=a.x;this->y=a.y;this->i=a.i;return *this;}
    friend istream& operator>>(istream &istm,pnt &a){istm>>a.x>>a.y;return istm;}
    friend ostream& operator<<(ostream &ostm,pnt &a){ostm<<"("<<a.x<<","<<a.y<<")";return ostm;}
    pnt operator+(const pnt &a)const{pnt t=*this;t.x+=a.x;t.y+=a.y;return t;}
    pnt operator-(const pnt &a)const{pnt t=*this;t.x-=a.x;t.y-=a.y;return t;}
    pnt operator/(const int &a)const{pnt t=*this;t.x/=a;t.y/=a;return t;}
    pnt& operator+=(const pnt &a){this->x+=a.x;this->y+=a.y;return *this;}
    pnt& operator/=(const int &a){this->x/=a;this->y/=a;return *this;}
};
ld dist(const pnt &a,const pnt &b){
    return (ld)sqrt((ld)((a-b).x*(a-b).x+(a-b).y*(a-b).y));
}


int n,m[805][805];
ld dp[805][805];
pnt a[805],avg;

bool cmp_theta(const pnt &a,const pnt &b){
    return atan2((ld)((a-avg).y),(ld)((a-avg).x))<atan2((ld)((b-avg).y),(ld)((b-avg).x));
}

void bt(int i,int j){
    if(abs(i-j)<2)return;
    cout<<a[i].i<<" "<<a[j].i<<'\n';
    if(m[i][j]==-1)return;
    bt(i,m[i][j]);
    bt(m[i][j],j);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i],a[i].i=i,avg+=a[i];
    avg/=n;
    // for(int i=0;i<n;++i)cout<<a[i]<<a[i].i<<" ";cout<<endl;
    sort(a,a+n,cmp_theta);
    // for(int i=0;i<n;++i)cout<<a[i]<<a[i].i<<" ";cout<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            m[i][j]=-1;
            dp[i][j]=100000000000.00;
            if(abs(i-j)<2)dp[i][j]=0.0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                if(dp[i][j]-(dp[i][k]+dp[k][j]+dist(a[i],a[j]))>1e-7){
                    dp[i][j]=dp[i][k]+dp[k][j]+dist(a[i],a[j]);
                    m[i][j]=k;
                }
            }
        }
    }
    int mini,minj;ld mindp=100500000000.00;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(abs(i-j)<2)continue;
            if(dp[i][j]<mindp){
                mindp=dp[i][j];
                mini=i,minj=j;
            }
        }
    }
    bt(mini,minj);
}
