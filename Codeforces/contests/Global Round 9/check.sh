for((i=0;;i++))
do
	echo $i
	./gen > in
	./a.out < in > out1
	./check 3< in 4< out1
done
