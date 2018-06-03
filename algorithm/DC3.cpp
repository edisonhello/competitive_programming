namespace DC3{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"

#define saveGet(v,i) ((i)>=int(v.size())?0:v[i])
#define SG saveGet
    bool smaller(int a, int b, vector<int> &ref){
        if(SG(ref,a+0) != SG(ref,b+0)) return SG(ref,a+0)<SG(ref,b+0);
        if(SG(ref,a+1) != SG(ref,b+1)) return SG(ref,a+1)<SG(ref,b+1);
        return SG(ref,a+2)<SG(ref,b+2);
    }
    
    int charCount[100005];
    vector<int> radixSort(vector<int> &ref, int offset, vector<int> &index, int sigma){
        vector<int> ret(index.size());
        for(int z=0;z<offset;++z) ref.push_back(0);
        for(int i=0;i<=sigma;++i) charCount[i] = 0;
        for(int i=0;i<index.size();++i) ++charCount[ref[index[i]+offset]];
        for(int i=0;i<=sigma;++i) charCount[i+1] += charCount[i];
        for(int i=index.size()-1;i>=0;--i) ret[--charCount[ref[index[i]+offset]]] = index[i];
        for(int z=0;z<offset;++z) ref.pop_back();
        return ret;
    }

    vector<int> dc3(vector<int> &value, int n, int sigma){
        int count1 = (n+1)/3;
        vector<int> working12;
        for(int i=0;i<n;++i){
            if(i%3==0)continue;
            working12.push_back(i);
        }
        working12 = radixSort(value, 2, working12, sigma);
        working12 = radixSort(value, 1, working12, sigma);
        working12 = radixSort(value, 0, working12, sigma);

        int nowRank = 1;
        vector<int> rank12(working12.size());
#define getReduceIndex(x) ((x)/3 + ((x)%3==2?count1:0))
#define GRI getReduceIndex
        rank12[GRI(working12[0])] = 1;
        for(int i=1;i<working12.size();++i){
            if(smaller(working12[i-1], working12[i], value)) rank12[GRI(working12[i])] = ++nowRank;
            else rank12[GRI(working12[i])] = nowRank;
        }

#define getExpandIndex(x) ((x)<count1?(x)*3+1:(x-count1)*3+2)
#define GEI getExpandIndex
        if(nowRank != working12.size()){
            working12 = dc3(rank12, working12.size(), nowRank);
            
            for(int i=0;i<working12.size();++i) rank12[working12[i]] = i+1;
            for(int &i: working12) i = GEI(i);
        }

        vector<int> working0;
        if(n%3==1) working0.push_back(n-1);
        for(int i=0;i<working12.size();++i) if(working12[i]%3 == 1) working0.push_back(working12[i]-1);
        working0 = radixSort(value, 0, working0, sigma);

        vector<int> ret(value.size());
        int ptr12=0, ptr0=0, ptr=0;
        while(ptr12<working12.size() && ptr0<working0.size()){
            if(working12[ptr12]%3 == 1){
                if([&](int i, int j) -> bool{
                    if(SG(value,i) != SG(value,j)) return SG(value,i)<SG(value,j);
                    return SG(rank12,GRI(i+1))<SG(rank12,GRI(j+1));
                }(working12[ptr12], working0[ptr0]))ret[ptr++] = working12[ptr12++];
                else ret[ptr++] = working0[ptr0++];
            }
            else{
                if([&](int i, int j) -> bool{
                    if(SG(value,i+0) != SG(value,j+0)) return SG(value,i+0)<SG(value,j+0);
                    if(SG(value,i+1) != SG(value,j+1)) return SG(value,i+1)<SG(value,j+1);
                    return SG(rank12,GRI(i+2))<SG(rank12,GRI(j+2));
                }(working12[ptr12], working0[ptr0]))ret[ptr++] = working12[ptr12++];
                else ret[ptr++] = working0[ptr0++];
            }
        }
        while(ptr12<working12.size()) ret[ptr++] = working12[ptr12++];
        while(ptr0<working0.size()) ret[ptr++] = working0[ptr0++];

        return ret;
    }
    vector<int> build(string str){
        vector<int> val(str.size()+1, 0);
        for(int i=0;i<str.size();++i) val[i] = str[i];
        return dc3(val, val.size(), 255);
    }
#pragma GCC diagnostic pop
}
