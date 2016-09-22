#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;scanf("%d",&n);
    queue<int> a;
    for(int i=1;i<=n;i++){
        a.push(i);
    }
    bool tag = false;
    while(a.size()>1){
        if(!tag){
            a.push(a.front());

        }
        a.pop();


        tag = !tag;
    }

    printf("%d",a.front());
}
