for((;;))
do
    ./gen > inn
    ./a.out < inn > out1
    ./tdd < inn > out2
    diff out1 out2 || break
done
