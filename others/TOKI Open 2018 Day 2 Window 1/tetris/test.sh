while [$1 == $1]
do
    ./gen > in
    ./tetris < in > out
    if cat out | grep -q 'jizzed'; then
        break
    fi
done
