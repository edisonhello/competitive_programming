for((i=0;i<10000;i++))
do
    ./gen > in
    ./a.out < in > out1
    ./ans < in > out2
    diff out1 out2 || break
done
