#include<iostream>
using namespace std;
int n,m,a;
int rowl[1005],rowr[1005],colu[1005],cold[1005];
int rowc[1005],colc[1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<1005;++i){
        rowl[i]=colu[i]=1006;
        rowr[i]=cold[i]=-565;
    }
    for(int i=0,t;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>t;
            if(t){
                ++rowc[i];
                ++colc[j];
                rowl[i]=min(rowl[i],j);
                rowr[i]=max(rowr[i],j);
                colu[j]=min(colu[j],i);
                cold[j]=max(cold[j],i);
            }
        }
    }
    for(int i=0;i<n;++i){
        if(rowl[i]!=1006){
            a+=m-rowl[i]-rowc[i];
        }
        if(rowr[i]!=-565){
            a+=rowr[i]+1-rowc[i];
        }
    }
    for(int j=0;j<m;++j){
        if(colu[j]!=1006){
            a+=n-colu[j]-colc[j];
        }
        if(cold[j]!=-565){
            a+=cold[j]+1-colc[j];
        }
    }
    cout<<a<<endl;
}
