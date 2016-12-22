#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int s,x1,x2,t1,t2,p,d,dd;

int proc1(){
    return abs(x1-x2)*t2;
}
int proc2(){
    if(x2==p)return 0;
    if(x2>p){
        if(dd==1){return (x2-p)*t1;}
        else{dd=1;return (x2+p)*t1;}
    }
    if(x2<p){
        if(dd==-1){return (p-x2)*t1;}
        else{dd=-1;return (s-p+s-x2)*t1;}
    }
}
int proc3(){
    if(dd=1)return (s-x2)*2*t1;
    else return x2*2*t1;
}
int proc4(){
    return s*2*t1;
}
bool proc5(){
    if(d==1 && x1<x2)return 1;
    if(d==1 && x2<p && p<x1)return 1;
    if(d==-1&& x1>x2)return 1;
    if(d==-1&& x2>p && p>x1)return 1;
    return 0;
}
bool proc6(){
    if(d==1 && x2>p && p>x1)return 0;
    if(d==-1&& x2<p && p<x1)return 0;
    return 1;
}

int main(){
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;dd=d;
    int walkTime=proc1();
    int carFstTime=proc2();
    int carloopOne=proc3();
    int carloopTwo=proc4();
    bool carPassOne=proc5();
    bool carPassTwo=proc6();
    // cout<<carPassOne<<" "<<carPassTwo<<endl;
    if(carPassOne){
        cout<<min(walkTime,carFstTime)<<endl;
    }
    else if(carPassTwo){
        cout<<min(walkTime,carFstTime+carloopOne)<<endl;
    }
    else{
        cout<<min(walkTime,carFstTime+carloopTwo)<<endl;
    }
}
