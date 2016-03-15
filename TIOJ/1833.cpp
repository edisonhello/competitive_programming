#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;scanf("%d %d",&n,&q);
    int *a = new int[n+5];
    for(int i=0;i<n+5;i++){
        a[i] = i;
    }
    for(int i=0;i<q;i++){
        string r;cin>>r;
        if(r[0] == 'M'){
            int in1,in2;scanf("%d %d",&in1,&in2);
            //if(in2 != in1){
                for(int j=0;j<n+5;j++){
                    if(a[j] == in2)a[j] = in1;
                }
            //}
        }
        else{
            int in;scanf("%d",&in);
            printf("%d\n",a[in]);
        }
    }
}
