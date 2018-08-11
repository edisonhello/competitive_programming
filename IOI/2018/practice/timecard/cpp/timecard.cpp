#include "timecard.h"

static int N;
void init(int n){
	N = n;
}
std::string convert(std::string s){
    for(char &c:s) if(c>='A' && c<='Z') c=c-'A'+'a';
    return s;
}
