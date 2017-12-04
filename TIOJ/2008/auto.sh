for((i=41; i<=43; i++));
do
    rm $i.in $i.out
    ./gen > $i.in
    ./ans < $i.in > $i.out
    sleep 2
done
