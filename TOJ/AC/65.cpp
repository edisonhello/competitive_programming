#include<cstdlib>
#include<ctime>
#include<iostream>
#include<unistd.h>
#include<sys/time.h>
using namespace std;
int main(){
    struct timeval tp;
        gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout<<(ms&1)<<endl;
}
