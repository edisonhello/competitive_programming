#include<iostream>
#include<cmath>

using namespace std;
int *a,*b,*c,n,cnt;

void dp(double f,double e){
//cout<<"f e ="<<f<<" "<<e<<endl;//while(f!=0)return;
//printf("f e = %.6lf %.6lf\n",f,e);
    if(abs(f-e)<=0.0000001){printf("%.6lf\n",e);return;}

    double mid1 = (2*f+e)/3;
    double mid2 = (f+e*2)/3;

    double mid1v = 2147483645;
    double mid2v = 2147483645;

    for(int i=0;i<n;i++){
        double t1 = a[i]*mid1*mid1+b[i]*mid1+c[i];
        double t2 = a[i]*mid2*mid2+b[i]*mid2+c[i];
        if(t1<mid1v){mid1v=t1;}
        if(t2<mid2v){mid2v=t2;}
    }

    //cout<<"mid1v mid2v="<<mid1v<<" "<<mid2v<<endl;
//printf("mid1v mid2v = %.6lf %.6lf , %d\n",mid1v,mid2v,mid1v<mid2v);
cnt++;
//if(cnt>=150)return;
/*if(mid1v==mid2v && !(abs(f-e)<=0.0000001)){
    dp(mid1,mid2);
}
    else{*/
        if(mid1v>=mid2v){dp(f,mid2);}
        else{dp(mid1,e);}
    //}
}

int main() {
    cin>>n;
cnt=0;
    a=new int[n];
    b=new int[n];
    c=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp(0,129600);
}
