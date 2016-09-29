#include<cstdio>
#include<stack>
#define MAX 1005
using namespace std;
stack<int> st;
int n,m,tmp,t,now=1,p[MAX],cnt[MAX];
bool in[MAX],f;

int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        f=false;
        scanf("%d",&tmp);
        while(!st.empty()&&in[st.top()])st.pop();
        while(st.empty()||(!st.empty()&&st.top()<tmp)){
            st.push(++now);
            p[now]=t;
            f=true;
        }
        if(f)t++;
        if(st.top()==tmp)st.pop();
        else {
            for(int i=p[tmp];i<t;i++)cnt[i]++;
            in[tmp]=true;
        }
    }
    f=false;
    for(int i=0;i<t;i++){
        if(cnt[i]>m)f=1;
    }
    if(f)puts("no");
    else puts("yes");
}
