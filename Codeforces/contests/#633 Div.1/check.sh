for ((i=0;;i++))
do
	./gen > in
	./a.out < in > out
	./bf < in > out2
	diff out out2 || break
done
