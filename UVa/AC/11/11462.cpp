#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        vector<int>a;
        for(int i=0;i<n;i++){
            int tmp;scanf("%d",&tmp);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(i)printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }

}
