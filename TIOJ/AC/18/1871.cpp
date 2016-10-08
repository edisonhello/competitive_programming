#include<vector>
#include<algorithm>
#include "lib1871.h"

using namespace std;
const int MAX = 2147483647;

int *tree;
int *ko;

int build(int l,int r,int id){
    //cout<<"jizz"<<l<<" "<<r<<" "<<id<<" "<<endl;
    if(l == r){
        //cout<<"return "<< ko[l] <<endl;
        return tree[id] = ko[l];
    }
    int mid = (l+r)/2;
    int res = min(build(l, mid, id*2), build(mid+1, r, id*2+1));
    tree[id] = res;

    return res;
}

int que(int l,int r,int id,int fl,int fr){
    if(r<fl || l>fr){
        return MAX;
    }
    if(l>=fl && r<=fr){
        return tree[id];
    }

    int mid = (l+r)/2;
    int res = min( que(l, mid, id*2, fl, fr), que(mid+1, r, id*2+1, fl , fr ));
    //cout<<"DE "<<l<<' '<<r<<' '<<res<<endl;
    return res;
}


int main(){
    int n = futa::init();// cout<<n<<endl;
    int *a = futa::momo_gives_you_list_of_futa();
    int q = futa::momo_tells_you_q();     //receive

    tree = new int[n*4];
                                //make array
    ko = a;
    //for(int i=0;i<n;i++)cout<<ko[i]<<' ';cout<<endl;


    build( 0 , n-1 , 1);                  //build tree
    //for(int i=0;i<10;i++)cout<<tree[i]<<' ';cout<<endl;

    for(int i=0;i<q;i++){
        pair<int,int> qt = futa::momo_asks();
        int ans = que(0, n-1, 1, qt.first, qt.second);
        futa::you_tell_momo(ans);
    }
}
