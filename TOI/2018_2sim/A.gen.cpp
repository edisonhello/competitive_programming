#include<bits/stdc++.h>
using namespace std;

int w[5005][5005];

int main(){
    srand(time(0));
    freopen("in.txt","w",stdout);
    int n=18,m1=50,m2=50;
    cout<<n<<" "<<m1<<" "<<m2<<endl;
    for(int i=0;i<m1+m2;++i){
        cout<<rand()%n<<" "<<rand()%n<<" "<<rand()%10<<endl;
    }
}


