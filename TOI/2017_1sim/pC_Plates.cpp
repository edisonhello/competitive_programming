#include<bits/stdc++.h>
using namespace std;


int a[123],n;
stack<int> plat;
vector<int> operation;
int onhand;
int OK;

bool yoooo(){
//    cout<<"inyoo"<<endl;
    for(int i=1;i<=n;++i)if(a[i]!=i)return 0;
    return 1;
}

int main(){
    cin>>n; OK=n+1;
    for(int i=n;i>0;--i)cin>>a[i];
    for(int i=1;i<n;++i){
        if(a[i]>a[i+1]){
            if(onhand){
                operation.push_back(a[i]);
                operation.push_back(a[i]);
                plat.push(a[i]);
            }
            else{
                operation.push_back(a[i]);
                onhand=a[i];
            }
        }
        else{
            operation.push_back(a[i]);
            operation.push_back(a[i]);
            plat.push(a[i]);
            if(onhand && onhand<a[i+1]){
                operation.push_back(onhand);
                plat.push(onhand);
                onhand=0;
            }
        }
    }
    operation.push_back(a[n]);
    operation.push_back(a[n]);
    plat.push(a[n]);
    if(onhand){
        operation.push_back(onhand);
        plat.push(onhand);
        onhand=0;
    }
    for(int i=n;i>0;--i){
        a[i]=plat.top();
        operation.push_back(plat.top());
        plat.pop();
    }
    // for(int i=1;i<=n;++i)cout<<a[i]<<" ";cout<<endl;
    while(1){
        if(yoooo())break;
//        for(int i=n;i>0;--i)cout<<a[i]<<" ";cout<<endl;
        while(a[OK-1]==(OK-1)){
            --OK;
        }
//        cout<<"OK = "<<OK<<endl;
        for(int i=1;i<OK-1;++i){
            if(a[i]>a[i+1]){
                if(onhand){
                    operation.push_back(a[i]);
                    operation.push_back(a[i]);
                    plat.push(a[i]);
                }
                else{
                    operation.push_back(a[i]);
                    onhand=a[i];
                }
            }
            else{
                operation.push_back(a[i]);
                operation.push_back(a[i]);
                plat.push(a[i]);
                if(onhand && onhand<a[i+1]){
                    operation.push_back(onhand);
                    plat.push(onhand);
                    onhand=0;
                }
            }
        }
        operation.push_back(a[OK-1]);
        operation.push_back(a[OK-1]);
        plat.push(a[OK-1]);
//        cout<<"on hand "<<onhand<<endl;
        if(onhand){
            operation.push_back(onhand);
            plat.push(onhand);
            onhand=0;
        }
//        cout<<"meow "<<plat.size()<<" "<<plat.top()<<endl;
        for(int i=OK-1;i>0;--i){
            a[i]=plat.top();
            operation.push_back(plat.top());
            plat.pop();
        }
    }

    cout<<operation.size()<<endl;
    for(int i:operation)cout<<i<<endl;
}
