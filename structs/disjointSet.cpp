struct disjointSet{
    std::vector<int> djs;
    void init(int size){
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){djs[F(x)]=F(y);}
    bool C(int x,int y){return F(x)==F(y);}
};

struct disjointSet{
    std::vector<int> djs,sz;
    void init(int size){
        sz.resize(size);
        djs.resize(size);
        for(int i=0;i<size;++i)djs[i]=i,sz[i]=1;
    }
    int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
    void U(int x,int y){x=F(x),y=F(y);if(sz[x]>sz[y])swap(x,y);djs[x]=y;}
    bool C(int x,int y){return F(x)==F(y);}
};
