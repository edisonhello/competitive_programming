#include<iostream>
#include<cmath>
#include<sstream>
#define ld long double
using namespace std;

int x[100005],y[100005];
int angs;

ld makeCos(int i,int j,int qx,int qy){
    ld a=sqrt((x[i]-qx)*(x[i]-qx)+(y[i]-qy)*(y[i]-qy)),
       b=sqrt((x[j]-qx)*(x[j]-qx)+(y[j]-qy)*(y[j]-qy)),
       c=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
    return (a*a+b*b-c*c)/(2*a*b);
}

int main(){
    while(cin>>x[0]>>y[0]){
        angs=1;
        string t1;
        stringstream ss;
        while(cin>>t1){
            if((t1[0]>='0'&&t1[0]<='9') || t1[0]=='-'){
                ss.clear();
                ss<<t1;
                ss>>x[angs];
                cin>>y[angs];
                ++angs;
            }
            else{
                if(t1!="Z"){
                    cin.ignore(1234,'Z');
                    cin.get();
                }
                break;
            }
        }
        cout<<angs<<endl;
        int qx,qy;
        while(cin>>t1){
            if((t1[0]>='0'&&t1[0]<='9') || t1[0]=='-'){
                ss.clear();
                ss<<t1;
                ss>>qx;
                cin>>qy;
                cin.ignore(1234,'Z');
                cin.get();
                ld ang=0;
                for(int i=0;i<angs-1;++i){
                    ang+=acos(makeCos(i,i+1,qx,qy));
                }
                ang+=acos(makeCos(angs-1,0,qx,qy));
                // cout<<qx<<" "<<qy<<" "<<ang<<endl;
                if(fabs(ang-6.28319)<1e-3){
                    cout<<"y\n";
                }
                else cout<<"n\n";
            }
            else{
                if(t1!="Z"){
                    cin.ignore(1234,'Z');
                    cin.get();
                }
                break;
            }
        }
        cout<<endl;
    }
}
