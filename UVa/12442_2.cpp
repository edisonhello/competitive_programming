#include<bits/stdc++.h>

using namespace std;

int rit(){
    int t=0;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t;
}

vector<pair<int,int> > rd;
bool *gone;int n;

int dfs(int now,int dep){           printf("dfs %d %d",now,dep);
    gone[now]=1;
    int mx=0;                       printf(" %d",gone[now]);
    for(int i=0;i<n;i++){           printf(" .%d n=%d, i=%d",rd[i].second,n,i);
        if(rd[i].first==now && !gone[rd[i].second]){    printf("go dfs %d\n",i);
            mx = max(mx,dfs(i,dep+1));
        }
    }       printf("come here\n");
    gone[now]=0;
    return mx;
}

int main(){
    int t=rit();
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        rd.clear();

        n=rit();
        for(int i=0;i<n;i++){
            int t1=rit(),t2=rit();
            rd.push_back(make_pair(t2-1,t1-1));
        }
        gone = new bool[n];
        memset(gone,0,sizeof(gone));
        //sort(rd.begin(),rd.end());


        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, dfs(i,0));
        }

        printf("%d\n",mx+1);

        delete gone;
    }
}
