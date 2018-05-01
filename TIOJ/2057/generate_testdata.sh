for i in {64..90}
do
    ./gen > $i.in
    ./ans < $i.in > $i.out
done
