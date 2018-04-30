for i in {1..100}
do
    ./gen > $i.in
    ./ans < $i.in > $i.out
done
