#include<bits/stdc++.h>

using namespace std;

/*inline int gcd(int a,int b){
    int mx = max(a,b);
    int mn = min(a,b);
    while(mn!=0){
        mx -= (mx/mn)*mn;
        int t=mx;mx=mn;mn=t;
    }
    return a;
}*/

priority_queue<int> q;
vector<int> e;
int a,b,c;
bool do_(){
    while(1){
        int t=q.top();q.pop();
        if(t%a==0||t%b==0){return 1;}
        if(t==0){return 1;}
        if(t<0){return 0;}
        if(a!=0)q.push(t-a);
        if(b!=0)q.push(t-b);
    }
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    if(a==1 || b==1){cout<<"Yes"<<endl;return 0;}

    q.push(c);
    bool _;
    while(1){
        int t=q.top();q.pop();//printf("%d\n",t);
        if(t%a==0||t%b==0){_=1;break;}
        if(t==0){_=1;break;}
        if(t<0){_=0;break;}
        if(a!=0){
            bool __=0;
            for(int i=0;i<e.size();i++){
                if(e[i]==t-a){
                    __=1;
                    break;
                }
            }
            if(!__){
                q.push(t-a);
                e.push_back(t-a);
            }
        }
        if(b!=0){
            bool __=0;
            for(int i=0;i<e.size();i++){
                if(e[i]==t-b){
                    __=1;
                    break;
                }
            }
            if(!__){
                q.push(t-b);
                e.push_back(t-b);
            }
        }
    }

    if(_)printf("Yes\n");
    else printf("No\n");
}
