for i in {57..63}
do
    ./gen > $i.in
    ./ans < $i.in > $i.out
    sleep 1
done
