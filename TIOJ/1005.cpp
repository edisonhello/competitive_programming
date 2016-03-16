#include<bits/stdc++.h>

using namespace std;

int gcd(int i,int j){
    int mx = max(i,j);
    int mn = min(i,j);

    mx -= mn*(mx/mn);
    if(mx==0){return mn;}
    return gcd(mx,mn);
}

inline bool hj(int i,int j){
    if(gcd(i,j)==1){return 1;}
    return 0;
}

int main(){
    int n;
    vector<int> a;
    while(cin>>n && n){
            a.clear();
        for(int i=0;i<n;i++){int t;cin>>t;a.push_back(t);}
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(hj(a[i],a[j]))cnt++;
            }
        }           //cout<<cnt<<" \n";
if(cnt==0){printf("No estimate for this data set.\n");continue;}
        float res = (float)(cnt*2) / (n*(n-1));  //cout<<res<<endl;
        float res2 = 6/res;
        float res3 = sqrt(res2);

        printf("%f\n",res3);
    }


}
