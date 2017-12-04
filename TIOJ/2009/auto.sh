for((i=48; i<=59; i++));
do
    ./gen > $i.in
    ./ans < $i.in > $i.out
    echo "finish $i."
    cat $i.out
    sleep 1.3
done
