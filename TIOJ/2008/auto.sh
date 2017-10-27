for((i=4; i<=10; i++));
do
    rm $i.in $i.out
    ./gen > $i.in
    ./ans < $i.in > $i.out
    sleep 2
done
