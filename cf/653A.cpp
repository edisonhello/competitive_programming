#include<bits/stdc++.h>
#define __ int
#define _____ cout<<"YES"<<endl;return 0;
#define ______ cout<<"NO"<<endl;
using namespace std;

__ main(){
    __ n;cin>>n;;
vector<__> ____;
    for(__ i=0;i<n;i++){
        __ _;cin>>_;
        bool ___=false;
        for(__ _______=0;_______<____.size();_______++){
            if(____[_______]==_){
                ___=true;
            }
        }
        if(___){
            continue;
        }
        ____.push_back(_);
    }

    sort(____.begin(),____.end());


    for(__ ___=0;___<n-2;___++){
        if(____[___]+2==____[___+1]+1 && ____[___+1]+1==____[___+2]){
            _____;
        }
    }

    ______;}
