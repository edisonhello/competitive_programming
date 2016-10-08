#include<bits/stdc++.h>
using namespace std;

int main()
{
    string as,bs,ac,bc;
    cin>>as>>bs;

    int adot=as.find('.');
    if(adot<0)adot=as.length();
    int bdot=as.find('.');
    if(bdot<0)bdot=bs.length();

    if(adot==1){
        ac="000"+as;
        adot+=3;
    }
    else if(adot==2){
        ac="00"+as;
        adot+=2;
    }
    else if(adot==3){
        ac="0"+as;
        adot++;
    }

    if(bdot==1){
        bc="000"+bs;
        bdot+=3;
    }
    else if(bdot==2){
        bc="00"+bs;
        bdot+=2;
    }
    else if(bdot==3){
        bc="0"+bs;
        bdot++;
    }

    // cout<<as<<endl<<bs;

    int i;
    for(i=0;i<ac.length()&&i<bc.length();i++){
        if(ac[i]>bc[i]){
            cout<<as<<endl;
            return 0;
        }
        else if(ac[i]<bc[i]){
            cout<<bs<<endl;
            return 0;
        }
    }
    if(!i<ac.length()){
        cout<<bs<<endl;
    }
    else{
        cout<<as<<endl;
    }
}
