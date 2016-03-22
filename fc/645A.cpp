#include<bits/stdc++.h>
using namespace std;
int main(){
    string poipoipoipoi;cin>>poipoipoipoi;
    string qwepoiqwepoi;cin>>qwepoiqwepoi;
    string qecpinqecpin;cin>>qecpinqecpin;
    string edcijnedcijn;cin>>edcijnedcijn;

    char alt=poipoipoipoi[0];
    char ald=qwepoiqwepoi[0];
    char art=poipoipoipoi[1];
    char ard=qwepoiqwepoi[1];

    char blt=qecpinqecpin[0];
    char bld=edcijnedcijn[0];
    char brt=qecpinqecpin[1];
    char brd=edcijnedcijn[1];

    string a="",b="";

    if(alt=='A'){
        a=alt;
        if(art!='X')a=a+art;
        if(ard!='X')a=a+ard;
        if(ald!='X')a=a+ald;
    }
    else if(art=='A'){
        a=art;
        if(ard!='X')a=a+ard;
        if(ald!='X')a=a+ald;
        if(alt!='X')a=a+alt;
    }
    else if(ard=='A'){
        a=ard;
        if(ald!='X')a=a+ald;
        if(alt!='X')a=a+alt;
        if(art!='X')a=a+art;
    }
    else if(ald=='A'){
        a=ald;
        if(alt!='X')a=a+alt;
        if(art!='X')a=a+art;
        if(ard!='X')a=a+ard;
    }
    if(blt=='A'){
        b=blt;
        if(brt!='X')b=b+brt;
        if(brd!='X')b=b+brd;
        if(bld!='X')b=b+bld;
    }
    else if(brt=='A'){
        b=brt;
        if(brd!='X')b=b+brd;
        if(bld!='X')b=b+bld;
        if(blt!='X')b=b+blt;
    }
    else if(brd=='A'){
        b=brd;
        if(bld!='X')b=b+bld;
        if(blt!='X')b=b+blt;
        if(brt!='X')b=b+brt;
    }
    else if(bld=='A'){
        b=bld;
        if(blt!='X')b=b+blt;
        if(brt!='X')b=b+brt;
        if(brd!='X')b=b+brd;
    }

    if(a==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
