for((i=0;;i++))
do
	./gen > in
	cat in
	./a.out < in || break
done
