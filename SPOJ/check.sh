for((;;))
do
    ./gen > in
    ./a.out < in > out1
    python ac.py < in > out2
    diff out1 out2 || break
    echo "yey"
done
