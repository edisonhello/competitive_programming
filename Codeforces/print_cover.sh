clang++ -fprofile-instr-generate -fcoverage-mapping -O2 $1 -o _qwe
LLVM_PROFILE_FILE="_qwee" ./_qwe < in > /dev/null
llvm-profdata merge -sparse _qwee -o _qweee
llvm-cov show ./_qwe -instr-profile=_qweee
rm _qwe _qwee _qweee
