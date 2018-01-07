for i in {71..72}
do
    ./gen > $i.in
    ./ans < $i.in > $i.out
    cat $i.out
    echo ""
    sleep 1
done
