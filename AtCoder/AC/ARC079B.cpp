#include<bits/stdc++.h>
using namespace std;

void p(vector<int> &a){
    return;
    cout<<"[";
    for(int i:a)cout<<i<<" ";
    cout<<"]"<<endl;
}

bool check(vector<int> &a){
    p(a);
    int n=a.size();
    for(int i:a)if(i>=n)return 0;
    return 1;
}
void ope(vector<int> &a){
    int n=a.size();
    int z=max_element(a.begin(),a.end())-a.begin();
    a[z]-=n;
    for(int i=0;i<n;++i){
        if(i==z)continue;
        ++a[i];
    }
}

int main(){
#ifndef WEAK
    long long k; cin >> k;
    if( k == 0 ) { cout << "2\n0 0" << endl; exit(0); }
    if( k == 2 ) { cout << "2\n2 2" << endl; exit(0); }
    if( k <= 10000 ) { cout << "2\n" << ( k % 3 == 2 ) << " " << k + !! ( k % 3 != 2 ) << endl; exit(0); }
    long long base = k / 50 + 49;
    if( k % 50 == 0 ) { cout << "50\n"; for( int i=0 ; i<50 ; ++i ) { cout << base << " "; } cout << endl; exit(0); }
    vector<long long> a(50, base - k % 50);
    for( int i=0 ; i<k%50 ; ++i) a[i] = base + 1;
    cout << 50 << endl;
    for( int i=0 ; i<50 ; ++i) cout << a[i] << " "; cout << endl;
    exit(0);
#else
    // vector<int> a(10,17);
    // a[0]=21; a[1]=21; a[2]=21;
    // vector<int> a(50,0);
    // stringstream ss("1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991227 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212 1991212");
    // for(int &i:a)ss>>i;
    vector<int> a; int n; cin>>n; a.resize(n);
    for(int &i:a)cin>>i;
    int cnt=0;
    while(!check(a)){
        ope(a);
        ++cnt;
    }
    cout<<cnt<<endl;
#endif
}

