for((i=0;;i++))
do
  ./gen > in
  ./a.out < in > out1
  ./tle < in > out2
  diff out1 out2 || break
  echo $i
done
