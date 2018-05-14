#include<bits/stdc++.h>
using namespace std;

int ary[111];
int main(){
    srand(time(NULL));
    freopen("in.txt","w",stdout);
    cout<<"2 1\n";
    for(int iiiii=0;iiiii<1;++iiiii){
        int N=rand()%50+51;
        for(int i=0;i<N;++i)ary[i]=i+1;
        random_shuffle(ary,ary+N);
        cout<<N<<" "<<N<<endl;
        for(int i=0;i<N;++i)cout<<ary[i]<<" ";
        cout<<endl;
    }
}
