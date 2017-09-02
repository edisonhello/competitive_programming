#include<iostream>
#include<bitset>
#include<string>
using namespace std;


namespace SHA1{
    uint_8 originalLength,blockCount,bitCount;
    bitset<512> b[65535];
    bitset<256> d[5];
    void checkBitPosition(){
        if(bitCount == 512){
            bitCount = 0;
            ++blockCount;
        }
    }
    void reset(){
        for(int i=0;i<blockCount;++i) b[i].reset();
        originalLength = blockCount = bitCount = 0;
        d[0] = 0x67452301;
        d[1] = 0xefcdab89;
        d[2] = 0x98badcfe;
        d[3] = 0x10325476;
        d[4] = 0xc3d2e1f0;
    }
    void init(string &s){
        for(char &c:s){
            for(int i=0;i<8;++i){
                b[blockCount][bitCount++] = c&(1<<(7-i));
                ++originalLength;
            }
            checkBitPosition();
        }
    }
    void padding(){
        b[blockCount][bitCount++] = 1;
        while(bitCount != 448){
            ++bitCount;
            checkBitPosition();
        }
        bitCount+=32;
        for(int i=0;i<32;++i)b[blockCount][bitCount++] = originalLength&(1<<(31-i));
        assert(bitCount == 512);
        checkBitPosition();
    }
    void processBlock(const int &blockNum){
        uint_8 w[79];
        for(int i=0;i<16;++i)w[i]=int((blockNum>>(i<<5)).to_ulong());
    }
    string SHA1(string s){
        reset();
        init(s);
        padding();
        for(int i=0;i<blockCount;++i)processBlock(i);
    }
}

int main(){
    
}
