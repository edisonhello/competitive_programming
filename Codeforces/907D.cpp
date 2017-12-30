#include<bits/stdc++.h>
using namespace std;

#define case(x,y) if(n==x && m==y)
#define NO return cout<<"NO"<<endl,0

int main(){
    int n,m; cin>>n>>m;
    case(1,1)NO;
    case(2,2)NO;
    case(1,2)NO;
    case(2,1)NO;
    case(2,3)NO;
    case(3,2)NO;
    case(3,1)NO;
    case(1,3)NO;
    case(3,3)cout<<"YES\n1 5 9 \n3 7 2\n4 6 8"<<endl,0;
    if(m!=3){
        int lastodd=(m+1)/2*2-1;
        int **a=new int*[n];
        for(int i=0;i<n;++i)a[i]=new int[m];
        for(int i=0,offset=0;i<n;++i,offset+=m){
            int fill=lastodd;
            for(int j=0;j<m;++j){
                a[i][j]=fill+offset;
                fill-=2;
                if(fill==-1)fill=m/2*2;
            }
        }
        for(int i=1;i<n;i+=2){
            int tmp=a[i][0];
            for(int j=0;j<m-1;++j)a[i][j]=a[i][j+1];
            a[i][m-1]=tmp;
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<a[i][j]<<" ";
            } cout<<endl;
        }
    }
    else{
        int lastodd=(n+1)/2*2;
        int **a=new int*[n];
        for(int i=0;i<n;++i)a[i]==new int[m];
        for(int i=0,ptr=0;i<n;++i)for(int j=0;j<m;++j)a[i][j]=++ptr;
        for(int j=0;j<3;++j){
            int *aa=new int[n];
            for(int i=0;i<n;++i)aa[i]=a[i][j];
            int lastodd=(n+1)/2*2-1,ptr=0;
            while(lastodd>0)a[ptr][j]=aa[lastodd],lastodd-=2,++ptr;
            int lasteven=n/2*2;
            while(lasteven>=0)a[ptr][j]=aa[lasteven],lasteven-=2,++ptr;
        }
        int tmp=a[0][1];
        for(int i=0;i<n-1;++i)a[i][1]=a[i+1][1];
        a[n-1][1]=tmp;
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<a[i][j]<<" ";
            } cout<<endl;
        }
    }
}
