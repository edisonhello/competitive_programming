#include<bits/stdc++.h>
using namespace std;

std::string exec(const char* cmd) {
    cout<<"exec: "<<cmd<<endl;
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

int main(){
    // exec("echo \"meow\" > test");
    srand(clock());
    while(1){
        string cmd="echo \"";
        stringstream ss1,ss2;
        ss1<<rand(); ss2<<rand();
        string s1,s2;
        ss1>>s1; ss2>>s2;
        cmd+=s1+" "+s2+"\" | ./gen > in";
        exec(cmd.c_str());
        string ra=exec("./a.out < in");
        string rb=exec("./lf < in");
        cout<<ra<<rb<<endl;
        if(ra!=rb)break;
    }
}
