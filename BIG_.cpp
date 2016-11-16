#include<cstring>
const BIGSize=500;
class BIG{
public:
    int length,a[BIGSize];
    BIG(){
        this->length=0;
        memset(this->a,0,sizeof(this->a));
    }
    BIG(int n){
        while(n){
            this->a[this->length++]=this->a%10;
            n/=10;
        }
    }
    BIG(long long n){
        while(n){
            this->a[this->length++]=this->a%10;
            n/=10;
        }
    }
}
