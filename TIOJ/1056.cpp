#include<string>
#include<iostream>
#include<ctime>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string f[3];
    cin>>f[0]>>f[1]>>f[2];

    int o=0,x=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(f[i][j]=='O'){
                o++;
            }
            else if(f[i][j]=='X'){
                x++;
            }
            else if(f[i][j]!='.'){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    int ol1=0,ol2=0,xl1=0,xl2=0;
    for(int i=0;i<3;i++){
        if(f[i][0]=='O'&&f[i][1]=='O'&&f[i][2]=='O'){
            ol1++;
        }
        if(f[0][i]=='O'&&f[1][i]=='O'&&f[2][i]=='O'){
            ol2++;
        }
        if(f[i][0]=='X'&&f[i][1]=='X'&&f[i][2]=='X'){
            xl1++;
        }
        if(f[0][i]=='X'&&f[1][i]=='X'&&f[2][i]=='X'){
            xl2++;
        }
    }

    int ow=0,xw=0;
    if(ol1+ol2 && xl1+xl2){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else if(ol1>1 || ol2>1 || xl1>1 ||xl2>1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else{
        if(ol1+ol2){
            ow=1;
        }
        else if(xl1+xl2){
            xw=1;
        }
    }


    if((o==x && ow!=1) || (o==x+1 && xw!=1)){
        cout<<"POSSIBLE\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

}
