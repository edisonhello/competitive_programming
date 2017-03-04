"""// import java.math.*;
// import java.util.*;
//
// public class UVa1647{
//     static BigInteger a[] = new BigInteger[1234];
//     static BigInteger i[] = new BigInteger[1234];
//     private static void init(){
//         a[0]=new BigInteger("0");
//         a[1]=new BigInteger("0");
//         a[2]=new BigInteger("1");
//         a[3]=new BigInteger("1");
//         i[3]=new BigInteger("1");
//         for(int n=4;n<=1000;++n){
//             if(n%2==0){
//                 a[n]=a[n-1].multiply(2).add(1);
//             }
//         }
//     }
//     public static void main(String[] args){
//         init();
//     }
// }"""

a=[0 for jiz in range(1005)]
i=[0 for jiz in range(1005)]
a[2]=1
a[3]=1
i[3]=1
for n in range(4,1002,1):
    if n%2==0:
        a[n]=a[n-1]*2+1
        i[n]=i[n-1]*2
    else:
        a[n]=a[n-1]+i[n-1];
        i[n]=a[n]

while True:
    try:
        n = int(input())
        print(a[n])
    except EOFError:
        break


"""/*
BIG a[1234],i[1234];
void init(){
    a[2]=1;
    a[3]=i[3]=1;
    for(int n=4;n<=1000;++n){
        if(n%2==0){
            a[n]=a[n-1]*2+1;
            i[n]=i[n-1]*2;
        }
        else{
            a[n]=i[n]=a[n-1]+i[n-1];
        }
    }
}

int main(){

    init();
    int n;while(cin>>n)cout<<a[n]<<endl;
}
*/"""
