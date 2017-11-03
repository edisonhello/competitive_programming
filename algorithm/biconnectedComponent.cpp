stack<int> st;
int in[1006],low[1006],bel[1006],bccc,timer;
vector<int> G[1006],bccmb[1006];

void dfs1(int now,int pa){
    in[now]=low[now]=++timer;
    st.push(now);
    for(int i:G[now]){
        if(i==pa)continue;
        if(in[i])low[now]=min(low[now],in[i]);
        else{
            dfs1(i,now);
            low[now]=min(low[now],low[i]);
            if(low[i]>=in[now]){
                ++bccc;
                while(0==0){
                    bccmb[bccc].push_back(st.top());
                    if(st.top()==i)break;
                    st.pop();
                }
                st.pop(); bccmb[bccc].push_back(now);
            }
        }
    }
}
