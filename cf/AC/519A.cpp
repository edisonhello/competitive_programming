#include<bits/stdc++.h>

using namespace std;

int main(){
    int cnt=72;
    int b=0,w=0;
    while(cnt--){
        char c=getchar();
        if(c=='.'){         //cout<<w<<" "<<b<<endl;
            continue;
        }
        if(c=='Q'){         //cout<<w<<" "<<b<<endl;
            w+=9;continue;
        }
        if(c=='q'){         //cout<<w<<" "<<b<<endl;
            b+=9;continue;
        }
        if(c=='R'){         //cout<<w<<" "<<b<<endl;
            w+=5;continue;
        }
        if(c=='r'){         //cout<<w<<" "<<b<<endl;
            b+=5;continue;
        }
        if(c=='B'||c=='N'){ //        cout<<w<<" "<<b<<endl;
            w+=3;continue;
        }
        if(c=='b'||c=='n'){ //        cout<<w<<" "<<b<<endl;
            b+=3;continue;
        }
        if(c=='P'){         //cout<<w<<" "<<b<<endl;
            w+=1;continue;
        }
        if(c=='p'){         //cout<<w<<" "<<b<<endl;
            b+=1;continue;
        }
    }

    if(w>b){
        cout<<"White"<<endl;
    }
    else if(w==b){
        cout<<"Draw\n";
    }
    else if(w<b){
        cout<<"Black\n";
    }
}
