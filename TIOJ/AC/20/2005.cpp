#include<bits/stdc++.h>
using namespace std;

struct raw{
    int d[3];
    int& operator[](int id){return d[id];}
    const int& operator[](int id)const{return d[id];}
};
struct mat{
    raw r[3];
    mat(){memset(r,0,sizeof(r));}
    raw& operator[](int id){return r[id];}
    const raw& operator[](int id)const{return r[id];}
    void setI(){for(int i=0;i<3;++i)for(int j=0;j<3;++j)r[i][j]=(i==j);}
};
int m;
mat operator*(const mat &a,const mat &b){
    mat rt;
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)rt[i][j]=(rt[i][j]+a[i][k]*b[k][j]%m)%m;
    return rt;
}

ostream& operator<<(ostream &ostm,const raw &r){ostm<<"["<<r[0]<<", "<<r[1]<<", "<<r[2]<<"]"; return ostm;}
ostream& operator<<(ostream &ostm,const mat &m){ostm<<"["<<m[0]<<",\n "<<m[1]<<",\n "<<m[2]<<"]"; return ostm;}

mat pow(mat b,int n){
    // cout<<"go pow "<<n<<endl;
    mat a; a.setI();
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } 
    // cout<<a<<endl;
    return a;
}

int main(){
    int n; while(cin>>n>>m){
        int now=1;
        mat ans; ans[0][1]=ans[0][2]=1;
        /* for(int i=1;i<=n;++i){
            mat itm; itm[0][0]=now*10; itm[1][0]=1; itm[1][1]=1; itm[2][1]=1; itm[2][2]=1;
            cout<<itm<<endl;
            ans=ans*itm;
            cout<<ans<<endl;
        }
        cout<<ans[0][0]<<endl;
        continue; */
        while(now<=n){
            mat itm; itm[0][0]=now*10%m; itm[1][0]=1; itm[1][1]=1; itm[2][1]=1; itm[2][2]=1;
            ans=ans*pow(itm,min(now*10-1,n)-now+1);
            now*=10;
        }
        cout<<ans[0][0]<<endl;
    }
}
