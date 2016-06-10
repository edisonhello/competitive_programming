#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    int pla[100][100];
    while(cin>>m>>n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>pla[j][i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j)cout<<" ";
                cout<<pla[i][j];
            }
            cout<<endl;
        }
    }
}
