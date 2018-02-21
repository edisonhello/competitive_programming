for i in {42..47}
do
    ./a.out > $i.in
    ./ans < $i.in > $i.out
    sleep 1
done
