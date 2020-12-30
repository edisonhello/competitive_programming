for((i=0;;i++))
do
	./gen > in
	./a.out < in > out1
	./bf < in > out2
	diff out1 out2 || break
	echo "==========="
	echo $i
	echo "====in====="
	cat in
	echo "====out===="
	cat out1
done
