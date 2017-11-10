$deg=<>;
print "YES\n2 1\n1 2" and exit if($deg==1);
print "NO" and exit if($deg%2==0);
$n=($deg+2)*2; $m=($deg+2)*$deg; $cnt=($deg-1)/2;
print "YES\n$n $m\n";
for($i=1;$i<=$deg+1;$i++){
    for($j=$i+1;$j<=$deg+1;$j++){
        if($cnt>0 && !$tag){
            $cnt--; $tag=2;
            push @stack,($i,$j) and next;
        }
        print "$i $j\n";
        ($_i,$_j)=wrp($i,$j);
        print "$_i $_j\n";
    }
    $tag--;
}
$mid=$deg+2; $mid2=$n+1-$mid;
print "$mid $mid2\n";
while(@stack){
    $a = pop @stack;
    $b = pop @stack;
    print "$a $mid\n$b $mid\n";
    ($a,$b)=wrp($a,$b);
    print "$a $mid2\n$b $mid2\n";
}
sub wrp{return ($n+1-@_[0],$n+1-@_[1]);}
