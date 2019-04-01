#include<bits/stdc++.h>
using namespace std;


int br[10][10];

int main(){
    int ts;cin>>ts;while(ts--){
        for(int i=1;i<=9;i+=2){
            for(int j=1;j<=i;j+=2){
                cin>>br[i][j];
            }
        }
        for(int i=3;i<=9;i+=2){
            for(int j=2;j<=i;j+=2){
                br[i][j]=(br[i-2][j-1]-br[i][j-1]-br[i][j+1])>>1;
            }
        }
        for(int i=2;i<=9;i+=2){
            for(int j=1;j<=i;++j){
                br[i][j]=br[i+1][j]+br[i+1][j+1];
            }
        }
        for(int i=1;i<=9;++i){
            for(int j=1;j<=i;++j){
                if(j-1)cout<<" ";
                cout<<br[i][j];
            } cout<<endl;
        }
    }
}
