#include<bits/stdc++.h>

#define print(x) printf("%d\n",x);

using namespace std;

inline int rit(){       //printf("jizz");
    int t=0,key=1;char c;

    do{
        c=getchar();
        if(c=='-')key=-1;
    }while(c<'0'||c>'9');
    do{
        t = t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*key;
}

int main(){         //printf("jizz");

    int n=rit();//printf("%d",n);
    short id[1000001];
    memset(id,0,sizeof(id));
    int now_mx = -1;
    int mxid;
    while(n--){
        int t=rit();            //cout<<t<<" ";
        id[t]++;                //cout<<now_mx<<" "<<mxid<<endl;
        if(id[t]>now_mx){
            now_mx = id[t];
            mxid = t;
        }
    }

    printf("%d\n",mxid);
}
