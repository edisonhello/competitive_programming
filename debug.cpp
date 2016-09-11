#include<iostream>

using namespace std;
int main()
{
    int a[5]={1,3,4,6,7};
    cout<<*lower_bound(a,a+5,5)<<endl;
}
