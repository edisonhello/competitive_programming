for((i=0;;i++))
do
  ./gen > in
  ./a.out < in || break
done
