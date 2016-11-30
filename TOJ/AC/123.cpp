#include<iostream>
using namespace std;
int n;
char w[2][100005];
int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>w[0][i];
    for(int i=0;i<n;++i)cin>>w[1][i];
    for(int i=0;i<n-1;++i){
        if(w[0][i]=='0'&&w[1][i]=='0'){
            cout<<"FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
        if(w[0][i+1]=='0'&&w[1][i]=='0'){
            cout<<"FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
        if(w[0][i]=='0'&&w[1][i+1]=='0'){
            cout<<"FENESTRATION FORTIFICATION FAILURE!\n";
            return 0;
        }
    }
    if(w[0][n-1]=='0'&&w[1][n-1]=='0'){
        cout<<"FENESTRATION FORTIFICATION FAILURE!\n";
        return 0;
    }
    cout<<"FENDED OFF!\n";
}
