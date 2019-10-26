for ((;;))
do
    ./gen > in
    ./a.out < in > out1
    ./bf < in > out3
    diff out1 out3 || break
done
