#include<bits/stdc++.h>
using namespace std;

int main(){
    int count = 10000;
    while( count -- ){
        system("./gen > in");
        system("./yp < in > yp_out");
        system("./my < in > my_out");
        system("./bk < in > bk_out");
        filebuf f_in, f_yp, f_my, f_bk;
        f_in.open("in", ios::in);
        f_yp.open("yp_out", ios::in);
        f_my.open("my_out", ios::in);
        f_bk.open("bk_out", ios::in);
        istream in(&f_in), yp(&f_yp), my(&f_my), bk(&f_bk);

        int ts; in >> ts;
        while( ts -- ){
            long long n, k, v; in >> n >> k >> v;
            string s; while( n -- ) in >> s;
            string my_ans, yp_ans, bk_ans;
            getline(my, my_ans);
            getline(yp, yp_ans);
            getline(bk, bk_ans);
            // cout<<my_ans<<" "<<yp_ans<<" "<<bk_ans<<endl;
            if(my_ans != yp_ans || my_ans != bk_ans){
                cout << "Error" << endl;
                return 0;
            }
            cout << "now ts : " << ts << endl;
        }
    }
    cout << "Finish." << endl;
}
