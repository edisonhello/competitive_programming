#include<bits/stdc++.h>
using namespace std;

int mp(char c){
    if(c=='I')return 1;
    if(c=='V')return 5;
    if(c=='X')return 10;
    if(c=='L')return 50;
    if(c=='C')return 100;
    if(c=='D')return 500;
    if(c=='M')return 1000;
    return 0;
}
int getn(string n){
    int nowmx=0;
    int ans=0;
    for(int i=n.length()-1;i>=0;i--){
        int thisc=mp(n[i]);
        if(thisc>=nowmx){
            nowmx=thisc;
            ans+=thisc;
        }
        else{
            ans-=thisc;
        }
    }
    return ans;
}

char revmap(int n){
    if(n==1)return 'I';
    if(n==5)return 'V';
    if(n==10)return 'X';
    if(n==50)return 'L';
    if(n==100)return 'C';
    if(n==500)return 'D';
    if(n==1000)return 'M';
    return 'Z';
}

string getro(int n){
    if(n==0){
        return "ZERO";
    }
    string ans;
    if(n>=1000){
        int times = n/1000;
        n%=1000;
        for(int i=0;i<times;i++){
            ans+="M";
        }
    }
    if(n>=900){
        n-=900;
        ans+="CM";
    }
    if(n>=800){
        n-=800;
        ans+="DCCC";
    }
    if(n>=700){
        n-=700;
        ans+="DCC";
    }
    if(n>=600){
        n-=600;
        ans+="DC";
    }
    if(n>=500){
        n-=500;
        ans+="D";
    }
    if(n>=400){
        n-=400;
        ans+="CD";
    }
    if(n>=300){
        n-=300;
        ans+="CCC";
    }
    if(n>=200){
        n-=200;
        ans+="CC";
    }
    if(n>=100){
        n-=100;
        ans+="C";
    }
    if(n>=90){
        n-=90;
        ans+="XC";
    }
    if(n>=80){
        n-=800;
        ans+="LXXX";
    }
    if(n>=70){
        n-=70;
        ans+="LXX";
    }
    if(n>=60){
        n-=60;
        ans+="LX";
    }
    if(n>=50){
        n-=50;
        ans+="L";
    }
    if(n>=40){
        n-=40;
        ans+="XL";
    }
    if(n>=30){
        n-=30;
        ans+="XXX";
    }
    if(n>=20){
        n-=20;
        ans+="XX";
    }
    if(n>=10){
        n-=10;
        ans+="X";
    }
    if(n==9){
        ans+="IX";
        return ans;
    }
    if(n>=5){
        ans+="V";
        n-=5;
    }
    if(n==4){
        ans+="IV";
        return ans;
    }
    for(;n>=1;n--){
        ans+="I";
    }
    return ans;
}

int main(){
    string a,b;
    while(cin>>a>>b && a!="#"){
        int m=getn(a),n=getn(b);
        // cout<<m<<n<<endl;
        string ans=getro(abs(m-n));
        cout<<ans<<endl;
    }
}
