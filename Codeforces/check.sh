for((;;))
do
    ./gen > in
    ./a.out < in > out1
    ./ans < in > out2
    diff out1 out2 || break
    echo "4"
done
